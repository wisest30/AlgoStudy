impl Solution {
    pub fn digit_count(num: String) -> bool {
        num.chars().enumerate().all(|e| {
            num.chars()
                .filter(|&c| c.to_digit(10).unwrap() as usize == e.0)
                .count()
                == e.1.to_digit(10).unwrap() as usize
        })
    }
}
