impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        use std::cmp::{min, max};
        let n = nums.len();
        let mut ps = vec![0; n+1];
        for i in 0..n { ps[i+1] = nums[i] + ps[i]; }
        let total = *ps.last().unwrap();
        (0..n)
        .map(|i| total - 
                 if i + total as usize <= n { ps[i + total as usize] - ps[i] }
                 else { ps[n] - ps[i] + ps[i + total as usize - n]})
        .min().unwrap()
    }
}
