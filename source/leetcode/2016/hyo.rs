use std::cmp::{max, min};
impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut ret = -1;
        let n = nums.len();
        for i in 0..n {
            for j in i+1..n {
                if nums[j] > nums[i] {
                    ret = max(ret, nums[j] - nums[i]);
                }
            }
        }
        return ret;
    }
}
