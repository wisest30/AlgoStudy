#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
        words.iter().filter(|w| w.starts_with(&pref)).count() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let words = ["pay", "attention", "practice", "attend"]
            .iter()
            .map(|s| s.to_string())
            .collect::<Vec<_>>();
        let pref = "at".to_string();
        let expected = 2;
        assert_eq!(expected, Solution::prefix_count(words, pref));

        let words = ["leetcode", "win", "loops", "success"]
            .iter()
            .map(|s| s.to_string())
            .collect::<Vec<_>>();
        let pref = "code".to_string();
        let expected = 0;
        assert_eq!(expected, Solution::prefix_count(words, pref));
    }
}
