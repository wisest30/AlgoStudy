#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        use std::cmp::Ordering;
        nums.windows(2)
            .map(|p| p[0].cmp(&p[1]))
            .filter(|&x| x != Ordering::Equal)
            .fold((Ordering::Equal, 0u32), |(prev, cnt), x| {
                if prev != Ordering::Equal && prev != x {
                    (x, cnt + 1)
                } else {
                    (x, cnt)
                }
            })
            .1 as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let nums = vec![1, 1, 2, 2, 3, 3, 2, 2, 3, 2, 1, 2, 1];
        let expected = 5;
        assert_eq!(expected, Solution::count_hill_valley(nums));
    }
}
