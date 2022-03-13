#![allow(unused)]

struct Solution {}

use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    // wrong answer on [53, 41, 90, 33, 84, 26, 50, 32, 63, 47, 66, 43, 29, 88, 71, 28, 83,], 76
    pub fn minimal_k_sum(nums: Vec<i32>, k: i32) -> i64 {
        // see https://leetcode.com/problems/append-k-integers-with-minimal-sum/discuss/1823630/n-*-(n-%2B-1)-2
        let mut k = k as i64;
        let nums = {
            let h: HashSet<i32> = HashSet::from_iter(nums);
            let mut x: Vec<_> = h.into_iter().collect();
            x.sort();
            x
        };

        let mut res = { k * (k + 1) / 2 };
        for n in nums {
            if n as i64 <= k {
                k += 1;
                res += k - n as i64;
            }
        }

        res
    }

    // right answer, TLE
    pub fn minimal_k_sum_naive(nums: Vec<i32>, k: i32) -> i64 {
        let k = k as usize;
        let h: HashSet<i32> = HashSet::from_iter(nums);

        (1..10i32.pow(9))
            .filter(|x| !h.contains(x))
            .map(|x| x as i64)
            .take(k)
            .sum()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let nums = vec![1, 4, 25, 10, 25];
        let k = 2;
        let expected = 5;
        assert_eq!(expected, Solution::minimal_k_sum(nums, k));

        let nums = vec![5, 6];
        let k = 6;
        let expected = 1 + 2 + 3 + 4 + 7 + 8;
        assert_eq!(expected, Solution::minimal_k_sum(nums, k));

        let nums = vec![
            53, 41, 90, 33, 84, 26, 50, 32, 63, 47, 66, 43, 29, 88, 71, 28, 83,
        ];
        let k = 76;
        let expected = 3444;
        assert_eq!(expected, Solution::minimal_k_sum(nums, k));
    }

    #[test]
    fn typical_cases_naive() {
        let nums = vec![1, 4, 25, 10, 25];
        let k = 2;
        let expected = 5;
        assert_eq!(expected, Solution::minimal_k_sum_naive(nums, k));

        let nums = vec![5, 6];
        let k = 6;
        let expected = 1 + 2 + 3 + 4 + 7 + 8;
        assert_eq!(expected, Solution::minimal_k_sum_naive(nums, k));

        let nums = vec![
            53, 41, 90, 33, 84, 26, 50, 32, 63, 47, 66, 43, 29, 88, 71, 28, 83,
        ];
        let k = 76;
        let expected = 3444;
        assert_eq!(expected, Solution::minimal_k_sum_naive(nums, k));
    }
}
