#![allow(unused)]

use std::{collections::HashSet, iter::FromIterator};

pub fn count_vowel_substrings(word: String) -> i32 {
    let l = word.len();
    let vowelset = HashSet::<u8>::from_iter("aeiou".as_bytes().iter().cloned());  
    //dbg!(vowelset.clone());

    (0..l)
        .map(move |i| ((i + 1)..l).map(move |j| i..=j))
        .flatten()
        //.inspect(|x| {dbg!(x);})
        .map(|r| word[r].as_bytes().iter().cloned())
        .map(|s| HashSet::<u8>::from_iter(s))
        //.inspect(|x| {dbg!(x);})
        .filter(|s_set| *s_set == vowelset)
        .count() as i32
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn count_vowel_substrings_typical() {
        let s = String::from("aeiouu");
        assert_eq!(2, count_vowel_substrings(s));

        let s = String::from("unicornarihan");
        assert_eq!(0, count_vowel_substrings(s));

        let s = String::from("cuaieuouac");
        assert_eq!(7, count_vowel_substrings(s));

        let s = String::from("bbaeixoubb");
        assert_eq!(0, count_vowel_substrings(s));
    }
}
