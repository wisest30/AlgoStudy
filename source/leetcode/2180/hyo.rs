impl Solution {
    pub fn count_even(num: i32) -> i32 {
        (1..=num)
        .filter(|&(mut x)| {
            let mut digit_sum = 0;
            while x > 0 {
                digit_sum += x % 10;
                x /= 10;
            }
            
            digit_sum % 2 == 0
        })
        .count() as i32
    }
}
