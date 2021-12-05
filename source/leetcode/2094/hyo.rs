impl Solution {
    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        let mut A = vec![false; 1000];
        let n = digits.len();
        for i in 0..n {
            for j in i+1..n {
                for k in j+1..n {
                    A[(digits[i] * 100 + digits[j] * 10 + digits[k]) as usize] = true;
                    A[(digits[i] * 100 + digits[k] * 10 + digits[j]) as usize] = true;
                    A[(digits[j] * 100 + digits[i] * 10 + digits[k]) as usize] = true;
                    A[(digits[j] * 100 + digits[k] * 10 + digits[i]) as usize] = true;
                    A[(digits[k] * 100 + digits[i] * 10 + digits[j]) as usize] = true;
                    A[(digits[k] * 100 + digits[j] * 10 + digits[i]) as usize] = true;
                }
            }
        }
        
        (100..1000).step_by(2).filter(|&x| A[x as usize]).collect::<Vec<i32>>()
    }
}
