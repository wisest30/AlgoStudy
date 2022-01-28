impl Solution {
    pub fn find_lonely(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort();
        let mut ret = Vec::new();
        for i in 0..nums.len() {
            let left = if i == 0 { i32::MIN } else { nums[i-1] };
            let right = if i == nums.len() - 1 { i32::MAX } else { nums[i+1] };
            if left + 1 < nums[i] && nums[i] + 1 < right {
                ret.push(nums[i]);
            }
        }
        ret
    }
}
