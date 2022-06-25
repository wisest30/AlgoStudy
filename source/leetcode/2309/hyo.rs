impl Solution {
    pub fn greatest_letter(s: String) -> String {
        use std::collections::HashSet;
        
        let s = s.chars().collect::<HashSet<char>>();
        let to_lower = |c| { (c as u8 - 'A' as u8 + 'a' as u8) as char};
        
        ('A'..='Z')
        .map(|c| if s.contains(&c) && s.contains(&to_lower(c)) { c.to_string() } else { "".to_string() })
        .max()
        .unwrap()
    }
}
