impl Solution {
    pub fn closest_meeting_node(edges: Vec<i32>, node1: i32, node2: i32) -> i32 {
        fn dfs(
            cur: usize,
            depth: usize,
            edges: &Vec<i32>,
            visited: &mut Vec<bool>,
            depth_vec: &mut Vec<usize>,
        ) {
            if visited[cur] {
                return;
            }

            visited[cur] = true;
            depth_vec[cur] = depth;
            let nxt = edges[cur];
            if nxt != -1 {
                dfs(nxt as usize, depth + 1, edges, visited, depth_vec);
            }
        }

        const inf: usize = std::usize::MAX;
        let n = edges.len();
        let mut d1 = vec![inf; n];
        let mut d2 = vec![inf; n];
        dfs(node1 as usize, 0, &edges, &mut vec![false; n], &mut d1);
        dfs(node2 as usize, 0, &edges, &mut vec![false; n], &mut d2);

        let mut min_val = inf;
        let mut min_idx = -1;
        for i in 0..n {
            let val = std::cmp::max(d1[i], d2[i]);
            if val < min_val {
                min_val = val;
                min_idx = i as i32;
            }
        }

        min_idx
    }
}
