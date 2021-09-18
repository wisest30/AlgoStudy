use std::vec::Vec;
use std::cmp;

fn max_len(v: Vec<char>) -> i32 {
    let n = v.len();
    let mut dp = vec![vec![0; n+1]; n+1];
    
    for i in 0..n {
        dp[i][i+1] = 1;
    }
    
    for len in 2..n+1 {
        for i in 0..n-len+1 {
            dp[i][i+len] = cmp::max(dp[i][i+len-1], dp[i+1][i+len]);
            if v[i] == v[i+len-1] {
                dp[i][i+len] = cmp::max(dp[i][i+len], dp[i+1][i+len-1] + 2);
            }
        }
    }
    
    dp[0][n]
}

impl Solution {
    pub fn max_product(s: String) -> i32 {
        let n = s.len();
        let mut ret = 0;
        for subset in 0..1 << n {
            let mut v1 = Vec::new();
            let mut v2 = Vec::new();
            
            for i in 0..n {
                if subset & (1 << i) != 0 {
                    v1.push(s.chars().nth(i).unwrap());
                } else{
                    v2.push(s.chars().nth(i).unwrap());
                }
            }
            
            let l1 = max_len(v1);
            let l2 = max_len(v2);
            
            ret = cmp::max(ret, l1 * l2);
        }
        
        ret
    }
}
