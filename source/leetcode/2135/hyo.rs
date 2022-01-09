impl Solution {
    pub fn word_count(start_words: Vec<String>, target_words: Vec<String>) -> i32 {
        use std::collections::HashSet;
        let stomask = |s : String| s.chars().enumerate().fold(0i32, |acc, (i, c)| acc | (1 << (c as u8 - b'a')));
        let start = start_words.into_iter().map(|s| stomask(s)).collect::<HashSet<_>>();
        target_words.into_iter().map(|s| {
            let mask = stomask(s);
            for i in 0..26 {
                if (mask & (1 << i)) > 0 && start.contains(&(mask - (1 << i))) {
                    return 1;
                }
            }
            0
        }).sum()
    }
}
