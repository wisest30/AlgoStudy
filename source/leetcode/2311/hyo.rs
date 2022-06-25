impl Solution {
    pub fn longest_subsequence(s: String, mut k: i32) -> i32 {
        let mut ret = 0;
        
        for c in s.chars().rev() {
            if c == '0' {
                ret += 1;
            } else if ret < 31 && (1 << ret) <= k {
                k -= 1 << ret;
                ret += 1;
            }
        }
        
        ret
    }
}
