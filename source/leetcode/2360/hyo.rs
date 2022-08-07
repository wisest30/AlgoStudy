impl Solution {
    pub fn longest_cycle(edges: Vec<i32>) -> i32 {
        fn dfs(
            cur: usize,
            depth: i32,
            depth_vec: &mut Vec<i32>,
            edges: &Vec<i32>,
            in_path: &mut Vec<bool>,
        ) -> i32 {
            in_path[cur] = true;
            depth_vec[cur] = depth;

            let nxt = edges[cur];
            let mut ret = -1;
            if nxt != -1 {
                let nxt = nxt as usize;
                if in_path[nxt] {
                    ret = std::cmp::max(ret, depth - depth_vec[nxt] + 1);
                } else if depth_vec[nxt] == -1 {
                    ret = std::cmp::max(ret, dfs(nxt, depth + 1, depth_vec, edges, in_path));
                }
            }

            in_path[cur] = false;
            ret
        }

        let mut ret = -1;
        let mut depth_vec = vec![-1; edges.len()];
        let mut in_path = vec![false; edges.len()];
        for i in 0..edges.len() {
            if depth_vec[i] == -1 {
                ret = std::cmp::max(ret, dfs(i, 0, &mut depth_vec, &edges, &mut in_path));
            }
        }

        ret
    }
}
