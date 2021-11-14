#![allow(unused)]

use std::{collections::HashSet, iter::FromIterator};

pub fn count_vowels(word: String) -> i64 {
    let vowels = "aeiou";
    let l = word.len();

    word.chars()
        .enumerate()
        .filter(|(_, c)| vowels.contains(*c))
        .map(|(i, _)| -> usize { (i + 1) * (l - i) })
        .sum::<usize>() as i64
}

pub fn count_vowels_bruteforce_tooslow(word: String) -> i64 {
    let l = word.len();
    let vowelset = HashSet::<u8>::from_iter("aeiou".as_bytes().iter().cloned());

    (0..l)
        .map(move |i| ((i + 1)..=l).map(move |j| i..j))
        .flatten()
        .map(|r| {
            word[r]
                .as_bytes()
                .iter()
                .filter(|c| vowelset.contains(c))
                .count()
        })
        .sum::<usize>() as i64
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn count_vowels_typical() {
        let s = String::from("aba");
        assert_eq!(6, count_vowels(s));

        let s = String::from("abc");
        assert_eq!(3, count_vowels(s));

        let s = String::from("ltcd");
        assert_eq!(0, count_vowels(s));

        let s = String::from("noosabasboosa");
        assert_eq!(237, count_vowels(s));
    }
}
