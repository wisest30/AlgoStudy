impl Solution {
    pub fn longest_continuous_substring(s: String) -> i32 {
        let mut ret = 1;
        let mut cur = 1;
        let mut prev = '_';
        for c in s.chars() {
            if prev as u8 + 1 == c as u8 {
                cur += 1;
            } else {
                cur = 1;
            }

            prev = c;
            ret = ret.max(cur);
        }

        ret
    }
}
