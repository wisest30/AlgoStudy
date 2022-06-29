impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        let mut b = false;
        let mut ret = 0;
        for c in s.chars() {
            if c == '*' && !b {
                ret += 1;
            } else if c == '|' {
                b = !b;
            }
        }
        
        ret
    }
}
