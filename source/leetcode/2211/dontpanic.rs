#![allow(unused)]

struct Solution {}

// idea from https://leetcode.com/problems/count-collisions-on-a-road/discuss/1865694/One-liner-in-Python
impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        directions
            .trim_start_matches('L')
            .trim_end_matches('R')
            .bytes()
            .filter(|&x| x != b'S')
            .count() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let directions = "RLRSLL".to_string();
        let expected = 5;
        assert_eq!(expected, Solution::count_collisions(directions));
    }
}
