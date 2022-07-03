impl Solution {
    pub fn people_aware_of_secret(n: i32, delay: i32, forget: i32) -> i32 {
        use std::cmp;

        const MOD: i64 = 1_000_000_007;

        let mut dp = vec![0i64; n as usize];
        dp[0] = 1;

        for i in 1..n {
            dp[i as usize] = dp
                [cmp::max(0, i - forget + 1) as usize..cmp::max(0, i - delay + 1) as usize]
                .iter()
                .sum::<i64>()
                % MOD;
        }

        (dp[dp.len() - forget as usize..].iter().sum::<i64>() % MOD) as i32
    }
}
