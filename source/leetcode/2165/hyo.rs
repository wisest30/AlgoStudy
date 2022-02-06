impl Solution {
    pub fn smallest_number(num: i64) -> i64 {
        let minus = if num < 0 { true } else { false };
        let num = num.abs();
        let mut s = num.to_string().chars().map(|c| c as u8 - '0' as u8).collect::<Vec<u8>>();
        s.sort();
        
        let mut ret = 0i64;
        if minus {
            for x in s.into_iter().rev() {
                ret = ret * 10 + x as i64;
            }
            ret = -ret;
        } else {
            if s[0] == 0 {
                for i in 1..s.len() {
                    if s[i] > 0 {
                        s[0] = s[i];
                        s[i] = 0;
                        break;
                    }
                }
            }
            for x in s.into_iter() {
                ret = ret * 10 + x as i64;
            }
        }
        
        ret
    }
}
