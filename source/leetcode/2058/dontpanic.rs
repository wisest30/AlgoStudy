#![allow(unused)]

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

pub fn nodes_between_critical_points(mut head: Option<Box<ListNode>>) -> Vec<i32> {
    let mut ifirst = -1;
    let mut ilast = -1;
    let mut dmin = -1;
    let mut i = 0;
    let mut prev = 0;
    let mut lastdiff = 0;

    while head.is_some() {
        let cur_head = head.unwrap();
        let cur = cur_head.val;

        if i == 0 {
        } else if i == 1 {
            lastdiff = cur - prev;
        } else {
            let diff = cur - prev;
            let crit = (diff > 0 && lastdiff < 0) || (diff < 0 && lastdiff > 0);
            if crit {
                let inew = i - 1;
                if ilast >= 0 {
                    // if other c.p. exist, check&update min distance
                    let d = inew - ilast;
                    dmin = if dmin < 0 {
                        d
                    } else if d < dmin {
                        d
                    } else {
                        dmin
                    };
                };
                if ifirst < 0 {
                    // if this is the first c.p.
                    ifirst = inew;
                };
                ilast = inew;
            }
            lastdiff = diff;
        };
        prev = cur;
        i += 1;

        head = cur_head.next;
    }

    let dmax = if ifirst > 0 && ilast > ifirst {
        ilast - ifirst
    } else {
        -1
    };

    vec![dmin, dmax]
}

pub fn nodes_between_critical_points_vec(v: Vec<i32>) -> Vec<i32> {
    let mut ifirst = -1;
    let mut ilast = -1;
    let mut dmin = -1;
    let mut i = 0;
    let mut prev = 0;
    let mut lastdiff = 0;

    for cur in v {
        if i == 0 {
        } else if i == 1 {
            lastdiff = cur - prev;
        } else {
            let diff = cur - prev;
            let crit = (diff > 0 && lastdiff < 0) || (diff < 0 && lastdiff > 0);
            if crit {
                let inew = i - 1;
                if ilast >= 0 {
                    // if other c.p. exist, check&update min distance
                    let d = inew - ilast;
                    dmin = if dmin < 0 {
                        d
                    } else if d < dmin {
                        d
                    } else {
                        dmin
                    };
                };
                if ifirst < 0 {
                    // if this is the first c.p.
                    ifirst = inew;
                };
                ilast = inew;
            }
            lastdiff = diff;
        };
        prev = cur;
        i += 1;
    }

    let dmax = if ifirst > 0 && ilast > ifirst {
        ilast - ifirst
    } else {
        -1
    };

    vec![dmin, dmax]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn nodes_between_critical_points_typical() {
        let v = vec![3, 1];
        assert_eq!(vec![-1, -1], nodes_between_critical_points_vec(v));

        let v = vec![5, 3, 1, 2, 5, 1, 2];
        assert_eq!(vec![1, 3], nodes_between_critical_points_vec(v));

        let v = vec![1, 3, 2, 2, 3, 2, 2, 2, 7];
        assert_eq!(vec![3, 3], nodes_between_critical_points_vec(v));

        let v = vec![2, 3, 3, 2];
        assert_eq!(vec![-1, -1], nodes_between_critical_points_vec(v));

        let v = vec![1, 2, 1, 2, 1, 2, 1, 2, 1];
        assert_eq!(vec![1, 6], nodes_between_critical_points_vec(v));
    }
}
