#![allow(unused)]
struct Solution {}

impl Solution {
    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        let mut cnt = {
            let mut v = vec![0; 10];
            for &i in digits.iter() {
                v[i as usize] += 1;
            }
            v
        };

        let mut ans = vec![0; 0];
        for i in (100..999).step_by(2) {
            let hunds = (i / 100) as usize;
            let tens = ((i % 100) / 10) as usize;
            let ones = (i % 10) as usize;

            // note: hundreds, tens, ones may be same.
            cnt[hunds] -= 1;
            cnt[tens] -= 1;
            cnt[ones] -= 1;

            if cnt[hunds] >= 0 && cnt[tens] >= 0 && cnt[ones] >= 0 {
                ans.push(i);
            }
            
            cnt[hunds] += 1;
            cnt[tens] += 1;
            cnt[ones] += 1;
        }
        
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn find_even_numbers_typical() {
        let digits = vec![2, 1, 3, 0];
        let expected = vec![102,120,130,132,210,230,302,310,312,320];
        assert_eq!(expected, Solution::find_even_numbers(digits));

        let digits = vec![2, 2, 8, 8, 2];
        let expected = vec![222, 228, 282, 288, 822, 828, 882];
        assert_eq!(expected, Solution::find_even_numbers(digits));

        let digits = vec![3, 7, 5];
        let expected = vec![0; 0];
        assert_eq!(expected, Solution::find_even_numbers(digits));

        let digits = vec![0, 2, 0, 0];
        let expected = vec![200];
        assert_eq!(expected, Solution::find_even_numbers(digits));

        let digits = vec![0, 0, 0];
        let expected = vec![0; 0];
        assert_eq!(expected, Solution::find_even_numbers(digits));
    }
}
