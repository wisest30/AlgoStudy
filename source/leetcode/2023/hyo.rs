impl Solution {
    pub fn num_of_pairs(nums: Vec<String>, target: String) -> i32 {
        let n = nums.len();
        let mut ret = 0;
        for i in 0..n {
            ret += nums
                   .iter()
                   .enumerate()
                   .filter(|&(j, _)| i != j && nums[i].clone() + &nums[j] == target)
                   .count();
        }
        
        ret as i32
    }
}
