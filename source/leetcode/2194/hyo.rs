impl Solution {
    pub fn cells_in_range(s: String) -> Vec<String> {
        let s = s.chars().collect::<Vec<_>>();
        let mut ret = Vec::new();
        for r in s[0]..=s[3] {
            for c in s[1]..=s[4] {
                ret.push(r.to_string() + &c.to_string());
            }
        }
        
        ret
    }
}
