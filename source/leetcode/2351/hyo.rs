impl Solution {
    pub fn repeated_character(s: String) -> char {
        let s = s.chars().collect::<Vec<char>>();
        for i in 0..s.len() {
            for j in 0..i {
                if s[i] == s[j] {
                    return s[i];
                }
            }
        }

        '_'
    }
}
