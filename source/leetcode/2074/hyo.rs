impl Solution {
    pub fn reverse_even_length_groups(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        use std::cmp::min;
        
        let mut A = Vec::new();
        let mut p = head.clone();
        while p.is_some() {
            let node = p.unwrap();
            A.push(node.val);
            p = node.next;
        }

        for g in 0..A.len() {
            let left = g * (g + 1) / 2;
            let right = min(left + g + 1, A.len());
            let len = right - left;
            
            if len % 2 == 0 { A[left..right].reverse(); }
            if right == A.len() { break; }
        }

        let mut cur = ListNode::new(A.pop().unwrap());
        while !A.is_empty() {
            let mut prev = ListNode::new(A.pop().unwrap());
            prev.next = Some(Box::new(cur));
            cur = prev;
        }
        
        Some(Box::new(cur))
    }
}
