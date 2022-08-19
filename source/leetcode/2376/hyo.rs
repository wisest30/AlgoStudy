use std::collections::HashSet;
impl Solution {
    pub fn count_special_numbers(n: i32) -> i32 {
        let mut fact = vec![0i32; 11];
        fact[0] = 1;
        for i in 1..=10 {
            fact[i] = fact[i - 1] * i as i32;
        }

        let mut ret = 0;
        let s = n
            .to_string()
            .chars()
            .map(|i| (i as u8 - '0' as u8) as i32)
            .collect::<Vec<i32>>();

        for i in 0..=s.len() {
            if i > 0 && s.iter().take(i-1).find(|&&x| x == s[i - 1]).is_some() {
                break;
            }

            if i < s.len() {
                for j in 0..s[i] {
                    if i == 0 && j == 0 || s.iter().take(i).find(|&&x| x == j).is_some() {
                        continue;
                    }

                    ret += fact[10 - i - 1] / fact[10 - s.len()];
                }
            } else {
                ret += fact[10 - i] / fact[10 - s.len()];
            }
        }

        for i in 1..s.len() {
            ret += 9 * fact[9] / fact[10 - i];
        }

        ret
    }
}
