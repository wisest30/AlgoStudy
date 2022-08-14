use std::collections::HashSet;
impl Solution {
    pub fn reachable_nodes(n: i32, edges: Vec<Vec<i32>>, restricted: Vec<i32>) -> i32 {
        fn dfs(cur: usize, par: usize, g: &Vec<Vec<usize>>, restricted: &HashSet<usize>) -> usize {
            if restricted.contains(&cur) {
                return 0;
            }

            let mut ret = 1;
            for &nxt in &g[cur] {
                if nxt == par {
                    continue;
                }

                ret += dfs(nxt, cur, g, restricted);
            }

            ret
        }

        let n = n as usize;
        let mut g = vec![vec![0; 0]; n];
        for edge in edges {
            g[edge[0] as usize].push(edge[1] as usize);
            g[edge[1] as usize].push(edge[0] as usize);
        }
        let restricted = restricted
            .into_iter()
            .map(|x| x as usize)
            .collect::<HashSet<_>>();

        dfs(0, n, &g, &restricted) as i32
    }
}
