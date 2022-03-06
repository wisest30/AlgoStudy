use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;
impl Solution {
    pub fn create_binary_tree(descriptions: Vec<Vec<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut map = HashMap::new();
        let mut indeg = HashMap::new();
        for d in descriptions {
            let par = map.entry(d[0]).or_insert(Rc::new(RefCell::new(TreeNode::new(d[0])))).clone();
            let child = map.entry(d[1]).or_insert(Rc::new(RefCell::new(TreeNode::new(d[1])))).clone();
            
            if d[2] == 1 {
                par.borrow_mut().left = Some(child);
            } else {
                par.borrow_mut().right = Some(child);
            }
            
            indeg.entry(d[0]).or_insert(0);
            *indeg.entry(d[1]).or_insert(0) += 1;
        }
        
        for (key, val) in indeg {
            if val == 0 {
                return Some(map.get(&key).unwrap().clone());
            }
        }
        
        None
    }
}
