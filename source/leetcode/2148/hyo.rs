impl Solution {
    pub fn count_elements(nums: Vec<i32>) -> i32 {
        let max_val = nums.iter().max().unwrap();
        let min_val = nums.iter().min().unwrap();
        nums.iter().filter(|&x| x < max_val && x > min_val).count() as i32
    }
}
