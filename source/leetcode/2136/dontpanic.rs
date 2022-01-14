#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn earliest_full_bloom(plant_time: Vec<i32>, grow_time: Vec<i32>) -> i32 {
        // https://leetcode.com/problems/earliest-possible-day-of-full-bloom/discuss/1676837/Grow-then-plant
        let gp_sorted = {
            let mut tmp: Vec<_> = grow_time.into_iter().zip(plant_time.into_iter()).collect();
            tmp.sort();
            tmp
        };

        gp_sorted
            .iter()
            .fold(0, |res, &(g, p)| std::cmp::max(res, g) + p)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let plant_time = vec![1, 4, 3];
        let grow_time = vec![2, 3, 1];
        assert_eq!(9, Solution::earliest_full_bloom(plant_time, grow_time));

        let plant_time = vec![1, 2, 3, 2];
        let grow_time = vec![2, 1, 2, 1];
        assert_eq!(9, Solution::earliest_full_bloom(plant_time, grow_time));

        let plant_time = vec![1];
        let grow_time = vec![1];
        assert_eq!(2, Solution::earliest_full_bloom(plant_time, grow_time));

        let plant_time = vec![3, 11, 29, 4, 4, 26, 26, 12, 13, 10, 30, 19, 27, 2, 10];
        let grow_time = vec![10, 13, 22, 17, 18, 15, 21, 11, 24, 14, 18, 23, 1, 30, 6];
        assert_eq!(227, Solution::earliest_full_bloom(plant_time, grow_time));
    }
}
