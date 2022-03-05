#![allow(unused)]

struct Solution {}

use std::collections::HashMap;

impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut h = HashMap::with_capacity(26);

        let sb = s.as_bytes().iter();
        sb.for_each(|&x| {
            *h.entry(x).or_insert(0i32) += 1;
        });

        let tb = t.as_bytes().iter();
        tb.for_each(|&x| {
            *h.entry(x).or_insert(0i32) -= 1;
        });

        h.values().map(|x| x.abs()).sum()
    }

    // from sample 2600 KB submission of leetcode statistics
    pub fn min_steps_simple(s: String, t: String) -> i32 {
        ('a'..='z')
            .map(|c| {
                (s.chars().filter(|&x| x == c).count() as i32
                    - t.chars().filter(|&x| x == c).count() as i32)
                    .abs()
            })
            .sum()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let s = "leetcode".to_string();
        let t = "coats".to_string();
        let expected = 7;
        assert_eq!(expected, Solution::min_steps(s, t));

        let s = "night".to_string();
        let t = "thing".to_string();
        let expected = 0;
        assert_eq!(expected, Solution::min_steps(s, t));
    }
}
