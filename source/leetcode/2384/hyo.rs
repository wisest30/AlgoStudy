impl Solution {
    pub fn largest_palindromic(num: String) -> String {
        let mut cnts = [0; 10];
        let nums = num
            .chars()
            .map(|x| x.to_digit(10).unwrap() as usize)
            .for_each(|x| {
                cnts[x] += 1;
            });

        let mut left = String::new();
        for i in (0..=9).rev() {
            let use_cnt = cnts[i] / 2;
            if use_cnt > 0 {
                left.push_str(&i.to_string().repeat(use_cnt));
                cnts[i] -= use_cnt * 2;
            }
        }

        if !left.is_empty() && left.chars().next().unwrap() == '0' {
            left = "".to_string();
        }

        let mid = if let Some(i) = (0..=9).filter(|&i| cnts[i] % 2 == 1).max() {
            i.to_string()
        } else {
            "".to_string()
        };

        let right = left.chars().rev().collect::<String>();

        let ret = left + &mid + &right;
        if ret.is_empty() {
            "0".to_string()
        } else {
            ret
        }
    }
}
