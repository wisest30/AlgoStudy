impl Solution {
    pub fn repeat_limited_string(s: String, repeat_limit: i32) -> String {
        let mut cnts = vec![0; 26];
        for c in s.chars() {
            cnts[c as usize - 'a' as usize] += 1;
        }
        
        let mut cs = Vec::new();
        let mut repeat = 0;
        for _ in 0..s.len() {
            for i in (0..26).rev() {
                if cnts[i] > 0 && !(repeat == repeat_limit && *cs.last().unwrap() == i) {
                    if !cs.is_empty() && *cs.last().unwrap() == i {
                        repeat += 1;
                    } else {
                        repeat = 1;
                    }
                    
                    cs.push(i);
                    cnts[i] -= 1;
                    break;
                }
            }
        }
        
        cs.into_iter().map(|x| (x as u8 + 'a' as u8) as char ).collect::<String>()
    }
}
