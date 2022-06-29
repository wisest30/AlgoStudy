impl Solution {
    pub fn dfs(cur: usize, visited: &mut Vec<bool>, e: &Vec<Vec<usize>>) -> usize {
        if visited[cur] {
            0
        } else {
            visited[cur] = true;
            let mut ret = 1usize;
            for &nxt in &e[cur] {
                ret += Solution::dfs(nxt, visited, &e);
            }
            ret
        }
    }
    
    pub fn count_pairs(n: i32, edges: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut e = vec![vec![0usize; 0]; n];
        for edge in edges {
            e[edge[0] as usize].push(edge[1] as usize);
            e[edge[1] as usize].push(edge[0] as usize);
        }
        
        let mut visited = vec![false; n];
        let mut ret = 0usize;
        for cur in 0..n {
            if !visited[cur] {
                let cnt = Solution::dfs(cur, &mut visited, &e);
                ret += cnt * (n - cnt);
            }
        }
        
        ret /= 2;
        ret as i64
    }
}
