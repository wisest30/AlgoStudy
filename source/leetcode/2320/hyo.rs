impl Solution {
    pub fn count_house_placements(n: i32) -> i32 {
        const mo: i64 = 1e9 as i64 + 7;
        
        let mut dp = [1, 2];
        for i in 2..=n {
            let nxt = (dp[0] + dp[1]) % mo;
            dp[0] = dp[1];
            dp[1] = nxt;
        }
        
        (dp[1] * dp[1] % mo) as i32
    }
}
