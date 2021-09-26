use std::collections::HashSet;
impl Solution {
    pub fn score_of_students(s: String, answers: Vec<i32>) -> i32 {
        let n = s.len();
        let mut dp = vec![vec![HashSet::new(); n+1]; n+1];
        let s = s.chars().collect::<Vec<char>>();
        for len in (1..=n).step_by(2) {
            for l in (0..=n-len).step_by(2) {
                let r = l + len;
                if len == 1 {
                    dp[l][r].insert(s[l].to_digit(10).unwrap() as i32);
                } else {
                    let mut hs = HashSet::new();
                    for m in (l+1..r).step_by(2) {
                        for &x in &dp[l][m] {
                            for &y in &dp[m+1][r] {
                                let z = if s[m] == '*' {x * y} else { x + y};
                                if z <= 1000 {
                                    hs.insert(z);
                                }
                            }
                        }
                    }
                    dp[l][r] = hs;
                }                
            }
        }
        
        let mut correct_ans = 0;
        let mut p = s[0].to_digit(10).unwrap() as i32;
        for i in (1..n).step_by(2) {
            if s[i] == '*' {
                p *= s[i+1].to_digit(10).unwrap() as i32;
            } else {
                correct_ans += p;
                p = s[i+1].to_digit(10).unwrap() as i32;
            }
        }
        correct_ans += p;
        
        let mut ret = 0;
        for ans in answers {
            if ans == correct_ans {
                ret += 5;
            } else if dp[0][n].contains(&ans) {
                ret += 2;
            }
        }
        
        ret
    }
}
