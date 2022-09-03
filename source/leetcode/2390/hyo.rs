impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut ret = String::new();
        s.chars().for_each(|c| {
            if c == '*' {
                ret.pop();
            } else {
                ret.push(c);
            }
        });

        ret
    }
}
