impl Solution {
    pub fn find_final_value(mut nums: Vec<i32>, original: i32) -> i32 {
        nums.sort();
        nums.iter().fold(original, |acc, &x| if acc == x { 2 * acc } else { acc })
    }
}
