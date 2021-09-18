use std::cmp::min;

impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        nums.sort();
        nums.dedup();
        
        let mut ret = n as i32;
        for i in 0..nums.len() {
            let right = nums[i] + n as i32;
            let idx = nums.binary_search(&right).unwrap_or_else(|x| x);
            let move_cnt = n - (idx - i);
            ret = min(ret, move_cnt as i32);
        }
        
        ret
    }
}
