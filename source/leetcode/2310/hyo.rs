impl Solution {
    pub fn minimum_numbers(num: i32, k: i32) -> i32 {
        if num == 0 {
            return 0;
        }
        
        for i in (1..=num) {
            if i * k <= num && i * k % 10 == num % 10 {
                return i;
            }
        }
        
        -1
    }
}
