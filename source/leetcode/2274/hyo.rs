impl Solution {
    pub fn max_consecutive(bottom: i32, top: i32, mut special: Vec<i32>) -> i32 {
        special.extend(vec![bottom - 1, top + 1]);
        special.sort_unstable();
        (1..special.len()).map(|i| special[i] - special[i-1] - 1).max().unwrap()
    }
}
