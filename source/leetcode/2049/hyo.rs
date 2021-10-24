impl Solution {
    // return : (node cnt, max score, max score cnt)
    fn dfs(g : &Vec<Vec<usize>>, cur : usize) -> Vec<i64> {
        let mut ret = vec![1, 0, 0];
        
        let mut score = 1i64;
        for &nxt in &g[cur] {
            let sub_ret = Solution::dfs(&g, nxt);
            ret[0] += sub_ret[0];
            score *= sub_ret[0];
            
            if ret[1] < sub_ret[1] {
                ret[1] = sub_ret[1];
                ret[2] = sub_ret[2];
            } else if ret[1] == sub_ret[1] {
                ret[2] += sub_ret[2];
            }
        }
        
        if cur > 0 {
            score *= g.len() as i64 - ret[0];
        }
        
        if ret[1] < score {
            ret[1] = score;
            ret[2] = 1;
        } else if ret[1] == score {
            ret[2] += 1;
        }

        ret
    }
    
    pub fn count_highest_score_nodes(parents: Vec<i32>) -> i32 {
        let n = parents.len();
        let mut g = vec![Vec::new(); n];
        for i in 1..n {
            g[parents[i] as usize].push(i);
        }

        Solution::dfs(&g, 0)[2] as i32
    }
}
