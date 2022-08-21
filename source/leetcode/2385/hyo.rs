use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;
impl Solution {
    pub fn amount_of_time(root: Option<Rc<RefCell<TreeNode>>>, start: i32) -> i32 {
        let mut g = vec![vec![0usize; 0]; 100001];

        pub fn node_dfs(cur: Rc<RefCell<TreeNode>>, g: &mut Vec<Vec<usize>>) {
            let cur_val = cur.as_ref().borrow().val as usize;
            if let Some(rc) = cur.as_ref().borrow().left.as_ref() {
                let child_val = rc.as_ref().borrow().val as usize;
                g[cur_val].push(child_val);
                g[child_val].push(cur_val);
                node_dfs(Rc::clone(rc), g);
            }
            if let Some(rc) = cur.as_ref().borrow().right.as_ref() {
                let child_val = rc.as_ref().borrow().val as usize;
                g[cur_val].push(child_val);
                g[child_val].push(cur_val);
                node_dfs(Rc::clone(rc), g);
            }
        }

        node_dfs(root.unwrap(), &mut g);

        let mut depth = vec![0usize; g.len()];
        pub fn dfs(cur: usize, par: usize, d: usize, depth: &mut Vec<usize>, g: &Vec<Vec<usize>>) {
            depth[cur] = d;
            for &nxt in &g[cur] {
                if nxt == par {
                    continue;
                }

                dfs(nxt, cur, d + 1, depth, g);
            }
        }

        dfs(start as usize, usize::MAX, 0, &mut depth, &g);
        depth.into_iter().max().unwrap() as i32
    }
}
