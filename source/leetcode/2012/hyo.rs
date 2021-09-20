use std::cmp::min;
use std::cmp::max;

impl Solution {
    pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut right_mins = vec![nums[n-1]; n];
        for i in (0..n-1).rev() {
            right_mins[i] = min(nums[i], right_mins[i+1]);
        }
        
        let mut left_max = nums[0];
        let mut ret = 0;
        for i in 1..n-1 {
            let right_min = right_mins[i+1];
            if left_max < nums[i] && nums[i] < right_min {
                ret += 2;
            } else if nums[i-1] < nums[i] && nums[i] < nums[i+1] {
                ret += 1;
            }
            
            left_max = max(left_max, nums[i]);
        }
        
        ret
    }
}
