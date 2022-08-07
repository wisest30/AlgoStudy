use std::collections::HashSet;
impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let set = nums.into_iter().collect::<HashSet<i32>>();
        if set.contains(&0) {
            set.len() as i32 - 1
        } else {
            set.len() as i32
        }
    }
}
