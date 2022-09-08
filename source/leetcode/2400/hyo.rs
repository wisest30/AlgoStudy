impl Solution {
    pub fn number_of_ways(start_pos: i32, end_pos: i32, k: i32) -> i32 {
        const MOD: i32 = 1_000_000_007;

        if (start_pos- end_pos).abs() > k {
            return 0;
        }

        let t = (end_pos - start_pos + k) as usize;
        let k = k as usize;
        let mut dp = vec![vec![0; 2 * k + 1]; k + 1];
        dp[0][k] = 1;

        for i in 0..k {
            for j in 0..2 * k + 1 {
                if j > 0 {
                    dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
                }
                if j < 2 * k {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                }
            }
        }

        dp[k][t]
    }
}
