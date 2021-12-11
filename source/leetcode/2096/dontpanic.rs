#![allow(unused)]

struct Solution {}

// ref: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/discuss/1613071/Idea-Explained-oror-LCA-Tree-Traversal-and-Backtracking-oror-C%2B%2B-Clean-Code

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn get_directions(
        root: Option<Rc<RefCell<TreeNode>>>,
        start_value: i32,
        dest_value: i32,
    ) -> String {
        let ans = String::new();

        let lca = get_lca(&root.as_ref(), start_value, dest_value);

        let mut path_from_lca_to_start = String::new();
        let mut path_from_lca_to_end = String::new();

        find_val_recursive_with_path(&lca.as_ref(), start_value, &mut path_from_lca_to_start);
        find_val_recursive_with_path(&lca.as_ref(), dest_value, &mut path_from_lca_to_end);

        "U".repeat(path_from_lca_to_start.len()) + path_from_lca_to_end.as_str()
    }
}

pub fn get_lca(
    root: &Option<&Rc<RefCell<TreeNode>>>,
    start: i32,
    dest: i32,
) -> Option<Rc<RefCell<TreeNode>>> {
    if let Some(&x) = root.as_ref() {
        let xb = x.borrow();
        if xb.val == start || xb.val == dest {
            Some(x.clone())
        } else {
            let left = get_lca(&xb.left.as_ref(), start, dest);
            let right = get_lca(&xb.right.as_ref(), start, dest);

            if left.is_some() && right.is_some() {
                Some(x.clone())
            } else {
                match left.is_some() {
                    true => left,
                    false => right,
                }
            }
        }
    } else {
        None
    }
}

pub fn find_val_recursive_with_path(
    root: &Option<&Rc<RefCell<TreeNode>>>,
    target_val: i32,
    path: &mut String,
) -> bool {
    if let Some(&x) = root.as_ref() {
        let xb = x.borrow();
        if xb.val == target_val {
            return true;
        } else {
            path.push('L');
            if find_val_recursive_with_path(&xb.left.as_ref(), target_val, path) {
                return true;
            }
            path.pop();

            path.push('R');
            if find_val_recursive_with_path(&xb.right.as_ref(), target_val, path) {
                return true;
            }
            path.pop();

            return false;
        }
    } else {
        return false;
    }
}

pub fn find_val(root: &Option<Rc<RefCell<TreeNode>>>, target_val: i32) {
    let mut nav_stack = Vec::new();

    if let Some(x) = root.as_ref() {
        nav_stack.push(x.clone());
    }
    while !nav_stack.is_empty() {
        let xptr = nav_stack.pop().unwrap();
        let x = xptr.as_ref().borrow();

        if x.val == target_val {
            break;
        } else {
            if let Some(x) = x.right.as_ref() {
                nav_stack.push(x.clone());
            }
            if let Some(x) = x.left.as_ref() {
                nav_stack.push(x.clone());
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn get_directions_typical() {
        // pass... for now.
    }
}

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
