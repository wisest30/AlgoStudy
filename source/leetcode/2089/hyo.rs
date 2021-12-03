impl Solution {
    pub fn target_indices(mut nums: Vec<i32>, target: i32) -> Vec<i32> {
        nums.sort();
        (0..nums.len() as i32)
        .filter(|&x| nums[x as usize] == target)
        .collect::<Vec<i32>>()
    }
}
