impl Solution {
    pub fn first_palindrome(words: Vec<String>) -> String {
        for s in words {
            if(s.chars().collect::<Vec<_>>() == s.chars().rev().collect::<Vec<_>>()) {
                return s;
            }
        }
        
        "".to_string()
    }
}
