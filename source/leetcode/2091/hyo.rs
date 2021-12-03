impl Solution {
    pub fn minimum_deletions(nums: Vec<i32>) -> i32 {
        use std::cmp::{max, min};
        
        let n = nums.len();
        
        if n == 1 {
            1
        } else {
            let mut max_val = nums[0];
            let mut min_val = nums[0];
            let mut max_idx = 0;
            let mut min_idx = 0;

            nums.iter().enumerate().for_each(|(i, &v)| {
                if v < min_val {
                    min_val = v;
                    min_idx = i;
                } else if v > max_val {
                    max_val = v;
                    max_idx = i;
                }
            });

            let a = min(min_idx, max_idx);
            let b = max(min_idx, max_idx);
            *[n - a, b + 1, a + 1 + n - b].iter().min().unwrap() as i32
        }
    }
}
