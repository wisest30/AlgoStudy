#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn minimum_deletions(nums: Vec<i32>) -> i32 {
        let l = nums.len() as i32;

        let (maxidx, _) = nums.iter().enumerate().max_by(|x, y| x.1.cmp(&y.1)).unwrap();
        let (minidx, _) = nums.iter().enumerate().min_by(|x, y| x.1.cmp(&y.1)).unwrap();
        let (a, b) = match maxidx > minidx {
            true => (minidx as i32, maxidx as i32),
            false => (maxidx as i32, minidx as i32),
        };

        let left = b + 1;
        let right = l - a;
        let both = (a + 1) + (l - b);

        *([left, right, both].iter().min().unwrap())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn minimum_deletions_typical() {
        let nums = vec![2,10,7,5,4,1,8,6];
        assert_eq!(5, Solution::minimum_deletions(nums));

        let nums = vec![0,-4,19,1,8,-2,-3,5];
        assert_eq!(3, Solution::minimum_deletions(nums));

        let nums = vec![101];
        assert_eq!(1, Solution::minimum_deletions(nums));
    }
}
