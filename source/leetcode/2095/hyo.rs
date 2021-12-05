impl Solution {
    pub fn delete_middle(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut n = 0usize;
        let mut cur = head.as_ref();
        while cur != None {
            cur = cur.unwrap().next.as_ref();
            n += 1
        }
        
        if n == 1 {
            return None;
        }
        
        let mut i = 0;
        let mut cur = head.as_mut();
        while cur != None {
            if i == n / 2 - 1 {
                cur.as_mut().unwrap().next = cur.as_ref().unwrap().next.as_ref().unwrap().next.clone();
                break;
            }

            cur = cur.unwrap().next.as_mut();
            i += 1;
        }

        return head;
    }
}
