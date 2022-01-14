#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn min_swaps(mut nums: Vec<i32>) -> i32 {
        let ones = nums.iter().sum::<i32>() as usize;

        nums.append(&mut nums.clone());
        let first: i32 = nums.iter().take(ones).sum();

        let it_sub = nums.iter();
        let it_addsub = it_sub.clone().skip(ones).zip(it_sub);

        let (_, max_ones_in_window) = it_addsub.fold((first, first), |(x, max), (&add, &sub)| {
            let x_new = x + add - sub;
            let max_new = std::cmp::max(max, x_new);
            (x_new, max_new)
        });

        ones as i32 - max_ones_in_window
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let nums = vec![0, 1, 0, 1, 1, 0, 0];
        assert_eq!(1, Solution::min_swaps(nums));
        let nums = vec![0, 1, 1, 1, 0, 0, 1, 1, 0];
        assert_eq!(2, Solution::min_swaps(nums));
        let nums = vec![1, 1, 0, 0, 1];
        assert_eq!(0, Solution::min_swaps(nums));
    }
}
