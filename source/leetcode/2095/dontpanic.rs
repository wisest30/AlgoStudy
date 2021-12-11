#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn delete_middle(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        use std::collections::VecDeque;
        let mut v = VecDeque::new();
        while head.is_some() {
            let h = head.unwrap();
            v.push_back(h.val);
            head = h.next;
        }
        v.remove(v.len() / 2);

        if v.is_empty() {
            None
        } else {
            let mut it = v.iter();
            let val = it.next().unwrap().clone();
            let mut ans = Some(Box::new(ListNode {
                val: val,
                next: None,
            }));
            let mut cur = &mut ans;

            for &i in it {
                let c = cur.as_mut().unwrap();
                c.next = Some(Box::new(ListNode { val: i, next: None }));
                cur = &mut c.next;
            }

            ans
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn delete_middle_typical() {
        // pass... for now.
    }
}

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}
