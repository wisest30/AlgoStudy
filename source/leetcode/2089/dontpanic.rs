#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let (lt, eq) = nums
            .iter()
            .fold((0, 0), |(lt, eq), n| match n.cmp(&target) {
                std::cmp::Ordering::Less => (lt + 1, eq),
                std::cmp::Ordering::Equal => (lt, eq + 1),
                std::cmp::Ordering::Greater => (lt, eq),
            });

        (lt..(lt + eq)).into_iter().collect()
    }

    pub fn target_indices_naive(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut sortednums = nums.clone();
        sortednums.sort();

        let res: Vec<_> = sortednums
            .iter()
            .enumerate()
            .filter(|(_, &x)| x == target)
            .map(|(x, _)| x as i32)
            .collect();

        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn target_indices_typical() {
        let nums = vec![1, 2, 5, 2, 3];
        let target = 2;
        let expected: Vec<i32> = vec![1, 2];
        assert_eq!(expected, Solution::target_indices(nums.clone(), target));
        assert_eq!(expected, Solution::target_indices_naive(nums, target));

        let nums = vec![1, 2, 5, 2, 3];
        let target = 3;
        let expected: Vec<i32> = vec![3];
        assert_eq!(expected, Solution::target_indices(nums.clone(), target));
        assert_eq!(expected, Solution::target_indices_naive(nums, target));

        let nums = vec![1, 2, 5, 2, 3];
        let target = 5;
        let expected: Vec<i32> = vec![4];
        assert_eq!(expected, Solution::target_indices(nums.clone(), target));
        assert_eq!(expected, Solution::target_indices_naive(nums, target));

        let nums = vec![1, 2, 5, 2, 3];
        let target = 4;
        let expected: Vec<i32> = vec![];
        assert_eq!(expected, Solution::target_indices(nums.clone(), target));
        assert_eq!(expected, Solution::target_indices_naive(nums, target));
    }
}
