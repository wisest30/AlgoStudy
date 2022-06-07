impl Solution {
    pub fn min_max_game(mut nums: Vec<i32>) -> i32 {
        while nums.len() > 1 {
            nums = (0..nums.len() / 2)
                .map(|i|
                    if i % 2 == 0 { std::cmp::min(nums[i * 2], nums[i * 2 + 1]) }
                    else { std::cmp::max(nums[i * 2], nums[i * 2 + 1]) })
                .collect::<Vec<i32>>();
        }
        
        nums[0]
    }
}
