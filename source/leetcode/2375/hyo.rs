impl Solution {
    pub fn smallest_number(pattern: String) -> String {
        let pattern = pattern.chars().collect::<Vec<char>>();
        let n = pattern.len();
        fn recur(candi: &mut Vec<i32>, n: usize, used: i32, pattern: &Vec<char>) -> bool {
            if candi.len() == n + 1 {
                true
            } else {
                let range = if candi.is_empty() {
                    1..=n as i32 + 1
                } else if pattern[candi.len() - 1] == 'D' {
                    1..=*candi.last().unwrap()
                } else {
                    *candi.last().unwrap() + 1..=n as i32 + 1
                };

                for i in range {
                    if (used & (1 << i)) == 0 {
                        candi.push(i);
                        let sub_ret = recur(candi, n, used | (1 << i), pattern);
                        if sub_ret {
                            return true;
                        }
                        candi.pop();
                    }
                }

                false
            }
        }

        let mut candi = Vec::new();
        let _ = recur(&mut candi, n, 0, &pattern);

        candi.into_iter().map(|i| i.to_string()).collect::<String>()
    }
}
