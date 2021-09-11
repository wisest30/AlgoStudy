impl Solution {
    pub fn first_day_been_in_all_rooms(NV: Vec<i32>) -> i32 {
        let MOD = 1000000007;
        let n = NV.len();
        
        let mut dp = vec![0i64; n];
        for i in 1..n {
            let x = NV[i-1] as usize;
            dp[i] = dp[i-1] + 1 + (dp[i-1] - dp[x]) + 1;
            dp[i] = (dp[i] + MOD) % MOD;
        }
        
        dp[n-1] as i32
    }
}
