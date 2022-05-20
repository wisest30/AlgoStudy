impl Solution {
    pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {
        pub fn counter(word: &String) -> Vec<usize> {
            ('a'..='z').map(|c| word.chars().filter(|&d| d == c).count()).collect::<Vec<_>>()
        }
        
        let mut ret = vec![];
        let mut prev = counter(&"".to_string());
        for word in words {
            let cur = counter(&word);
            if prev != cur {
                ret.push(word);
                prev = cur;
            }
        }
        
        ret
    }
}
