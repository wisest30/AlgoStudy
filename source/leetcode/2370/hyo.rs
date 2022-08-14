use std::cmp::max;
impl Solution {
    pub fn longest_ideal_string(s: String, k: i32) -> i32 {
        let mut dp = vec![-1; 26];
        for c in s.chars() {
            let i = (c as u8 - 'a' as u8) as usize;

            if dp[i] == -1 {
                dp[i] = 1;
            } else {
                dp[i] += 1;
            }

            for j in 0..26 {
                if i != j && (i as i32 - j as i32).abs() <= k {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        dp.into_iter().max().unwrap()
    }
}
