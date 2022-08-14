impl Solution {
    pub fn valid_partition(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut dp = vec![false; n + 1];
        dp[0] = true;
        for i in 2..=n {
            if dp[i - 2] && nums[i - 2] == nums[i - 1] {
                dp[i] = true;
            } else if i >= 3
                && dp[i - 3]
                && nums[i - 3] == nums[i - 2]
                && nums[i - 2] == nums[i - 1]
            {
                dp[i] = true;
            } else if i >= 3
                && dp[i - 3]
                && nums[i - 3] + 1 == nums[i - 2]
                && nums[i - 2] + 1 == nums[i - 1]
            {
                dp[i] = true;
            }
        }

        dp[n]
    }
}
