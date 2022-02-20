// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut v = Vec::new();
        let mut cur = head.as_ref();
        while !cur.is_none() {
            if cur.unwrap().val == 0 {
                v.push(0);
            } else {
                let len = v.len();
                v[len - 1] += cur.unwrap().val;
            }
            
            cur = cur.unwrap().next.as_ref();
        }
        
        v.pop();
        
        let mut ret = Some(Box::new(ListNode::new(v[0])));
        let mut cur = ret.as_mut().unwrap();
        for i in 1..v.len() {
            cur.next = Some(Box::new(ListNode::new(v[i])));
            cur = cur.next.as_mut().unwrap();
        }
        
        ret
    }
}
