impl Solution {
    pub fn count_vowels(word: String) -> i64 {
        word
        .chars()
        .enumerate()
        .filter(|(i, c)| *c == 'a' || *c == 'e' || *c == 'i' || *c == 'o' || *c == 'u')
        .fold(0i64, |acc, (i, c)| acc + (i + 1) as i64 * (word.len() - i) as i64)
    }
}
