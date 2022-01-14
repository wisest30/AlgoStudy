#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn word_count(start_words: Vec<String>, target_words: Vec<String>) -> i32 {
        // Rust rewrite from https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/discuss/1676859/Trie-vs.-Bitmask-vs.-Sorting
        use std::collections::HashSet;
        let atobit = |b: u8| 1 << (b - b'a');
        let get_mask = |w: &str| w.as_bytes().iter().fold(0, |prev, &x| prev | atobit(x));

        let mut s = HashSet::<u32>::new();
        for w in start_words {
            let mask = get_mask(&w);
            // println!("{:#034b} {}", &mask, &w);
            s.insert(mask);
        }

        target_words
            .iter()
            .map(|w| {
                let mask = get_mask(w);
                // println!("{:#034b} {}", &mask, &w);
                w.as_bytes()
                    .iter()
                    .map(|&x| mask & !atobit(x))
                    // .inspect(|x| println!("{:#034b}", x))
                    .any(|x| s.contains(&x))
            })
            .filter(|&x| x)
            .count() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let start_words = ["ant", "act", "tack"]
            .iter()
            .map(|&x| String::from(x))
            .collect();
        let target_words = vec!["tack", "act", "acti"]
            .iter()
            .map(|&x| String::from(x))
            .collect();
        assert_eq!(2, Solution::word_count(start_words, target_words));
        // let word_count = vec!["ab", "a"];
        // let word_count = vec!["abc", "abcd"];
    }
}
