impl Solution {
    pub fn selling_wood(m: i32, n: i32, prices: Vec<Vec<i32>>) -> i64 {
        use std::cmp::{max, min};
        
        let m = m as usize;
        let n = n as usize;
        
        let mut dp = vec![vec![0i64; n + 1]; m + 1];
        let mut p = vec![vec![0i64; n + 1]; m + 1];
        for price in prices {
            p[price[0] as usize][price[1] as usize] = price[2] as i64;
        }
        
        for r in 1..=m {
            for c in 1..=n {
                dp[r][c] = p[r][c];
                for k in 1..r {
                    dp[r][c] = max(dp[r][c], dp[k][c] + dp[r - k][c]);
                }
                for k in 1..c {
                    dp[r][c] = max(dp[r][c], dp[r][k] + dp[r][c - k]);
                }
            }
        }
        
        dp[m][n]
    }
}
