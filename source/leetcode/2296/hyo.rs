use std::rc::Rc;
use std::cell::RefCell;

struct Node {
    val: char,
    next: Option<Rc<RefCell<Node>>>,
    prev: Option<Rc<RefCell<Node>>>,
}

impl Node {
    fn new(val: char) -> Self {
        Node {val, next: None, prev: None }
    }
}

struct TextEditor {
    cur_r: Option<Rc<RefCell<Node>>>,
    cur_l: Option<Rc<RefCell<Node>>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TextEditor {

    fn new() -> Self {
        TextEditor{cur_r: None, cur_l: None}
    }
    
    fn add_text(&mut self, text: String) {
        for c in text.chars() {
            let node = Rc::new(RefCell::new(Node::new(c)));
            if self.cur_l.is_some() {
                node.borrow_mut().prev = Some(Rc::clone(self.cur_l.as_ref().unwrap()));
                self.cur_l.as_mut().unwrap().borrow_mut().next = Some(Rc::clone(&node));
            }
            if self.cur_r.is_some() {
                node.borrow_mut().next = Some(Rc::clone(self.cur_r.as_ref().unwrap()));
                self.cur_r.as_mut().unwrap().borrow_mut().prev = Some(Rc::clone(&node));
            }

            self.cur_l = Some(node);
        }
    }
    
    fn delete_text(&mut self, k: i32) -> i32 {
        let mut ret = 0;
        for i in 0..k {
            if self.cur_l.is_none() {
                break;
            } else {
                let del_rc = Rc::clone(self.cur_l.as_ref().unwrap());
                self.cur_l = if del_rc.borrow().prev.is_some() {
                    Some(Rc::clone(del_rc.borrow().prev.as_ref().unwrap()))
                } else {
                    None
                };
                
                if self.cur_l.is_some() {
                    self.cur_l.as_mut().unwrap().borrow_mut().next =
                        if self.cur_r.is_some() { Some(Rc::clone(self.cur_r.as_ref().unwrap())) }
                        else { None };
                }
                
                if self.cur_r.is_some() {
                    self.cur_r.as_mut().unwrap().borrow_mut().prev =
                        if self.cur_l.is_some() { Some(Rc::clone(self.cur_l.as_ref().unwrap())) }
                        else { None };
                }
                
                del_rc.borrow_mut().next = None;
                del_rc.borrow_mut().prev = None;
                
                ret += 1;
            }
        }
        
        ret
    }
    
    fn cursor_left(&mut self, k: i32) -> String {
        for i in 0..k {
            if self.cur_l.is_some() {
                self.cur_r = Some(Rc::clone(self.cur_l.as_ref().unwrap()));
                self.cur_l = if self.cur_r.as_ref().unwrap().borrow().prev.is_some() {
                    Some(Rc::clone(self.cur_r.as_ref().unwrap().borrow().prev.as_ref().unwrap()))
                } else {
                    None
                };
            } else {
                break;
            }
        }
        
        self.get_left_str()
    }
    
    fn cursor_right(&mut self, k: i32) -> String {
        for i in 0..k {
            if self.cur_r.is_some() {
                self.cur_l = Some(Rc::clone(self.cur_r.as_ref().unwrap()));
                self.cur_r = if self.cur_l.as_ref().unwrap().borrow().next.is_some() {
                    Some(Rc::clone(self.cur_l.as_ref().unwrap().borrow().next.as_ref().unwrap()))
                } else {
                    None
                };
            } else {
                break;
            }
        }
        
        self.get_left_str()
    }
    
    fn get_left_str(&mut self) -> String {
        if self.cur_l.is_none() {
            return "".to_string();
        }
        
        let mut chars = Vec::new();
        let mut rc = Rc::clone(self.cur_l.as_ref().unwrap());
        for i in 0..10 {
            chars.push(rc.borrow().val);
            if rc.borrow().prev.is_none() {
                break;
            } else {
                let prev = Rc::clone(rc.borrow().prev.as_ref().unwrap());
                rc = prev;
            }
        }
        
        chars.iter().rev().collect::<String>()
    }
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * let obj = TextEditor::new();
 * obj.add_text(text);
 * let ret_2: i32 = obj.delete_text(k);
 * let ret_3: String = obj.cursor_left(k);
 * let ret_4: String = obj.cursor_right(k);
 */
