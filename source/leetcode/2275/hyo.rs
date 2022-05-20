impl Solution {
    pub fn largest_combination(candidates: Vec<i32>) -> i32 {
        (0..30).map(|i| candidates.iter().map(|c| c & (1 << i)).filter(|&x| x > 0).count()).max().unwrap() as i32
    }
}
