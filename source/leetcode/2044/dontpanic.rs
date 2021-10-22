// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/discuss/1525309/
// int countMaxOrSubsets(vector<int>& A) {
//     int max = 0, dp[1 << 17] = {1};
//     for (int a: A) {
//         for (int i = max; i >= 0; --i)
//             dp[i | a] += dp[i];
//         max |= a;
//     }
//     return dp[max];
// }

pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
    let mut max = 0;
    let mut dp = vec![0; 1 << 17];
    dp[0] = 1;
    for n in nums {
        for i in (0..=max).rev() {
            dp[(i | n) as usize] += dp[i as usize];
        }
        max |= n;
    }
    dp[max as usize]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn count_max_or_subsets_typical() {
        assert_eq!(2, count_max_or_subsets(vec![3, 1]));
        assert_eq!(7, count_max_or_subsets(vec![2, 2, 2]));
        assert_eq!(6, count_max_or_subsets(vec![3, 2, 1, 5]));
    }
}
