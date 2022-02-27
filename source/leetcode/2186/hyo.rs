impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        ('a'..='z')
        .map(|c| (s.chars().filter(|&x| x == c).count() as i32 - t.chars().filter(|&x| x == c).count() as i32).abs())
        .sum()
    }
}
