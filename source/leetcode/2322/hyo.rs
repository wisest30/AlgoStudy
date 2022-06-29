impl Solution {
    pub fn minimum_score(nums: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        use std::cmp::{max, min};
        
        let n = nums.len();
        let mut g = vec![vec![0; 0]; n];
        for edge in edges {
            g[edge[0] as usize].push(edge[1] as usize);
            g[edge[1] as usize].push(edge[0] as usize);
        }
        
        pub fn dfs(
            cur: usize,
            prev: usize,
            g: &Vec<Vec<usize>>,
            vals: &mut Vec<i32>,
            st: &mut Vec<i32>,
            et: &mut Vec<i32>,
            time: &mut i32)
        {
            st[cur] = *time;
            *time += 1;
            
            for &nxt in &g[cur] {
                if nxt == prev {
                    continue;
                }
                
                dfs(nxt, cur, g, vals, st, et, time);
                vals[cur] ^= vals[nxt];
            }
            
            et[cur] = *time;
            *time += 1;
        }
        
        let mut vals = nums;
        let mut st = vec![0; n];
        let mut et = vec![0; n];
        dfs(0, n, &g, &mut vals, &mut st, &mut et, &mut 0);
        
        let mut ret = std::i32::MAX;
        for i in 1..n {
            for j in i+1..n {
                let mut a = 0;
                let mut b = 0;
                let mut c = 0;
                if st[i] < st[j] && et[j] < et[i] {
                    a = vals[0] ^ vals[i];
                    b = vals[i] ^ vals[j];
                    c = vals[j];
                } else if st[j] < st[i] && et[i] < et[j] {
                    a = vals[0] ^ vals[j];
                    b = vals[j] ^ vals[i];
                    c = vals[i];                    
                } else {
                    a = vals[0] ^ vals[i] ^ vals[j];
                    b = vals[i];
                    c = vals[j];
                }
                
                let max_val = max(a, max(b, c));
                let min_val = min(a, min(b, c));
                
                ret = min(ret, max_val - min_val);
            }
        }
        
        ret
    }
}
