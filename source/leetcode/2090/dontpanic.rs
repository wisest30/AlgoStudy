#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn get_averages(nums: Vec<i32>, r: i32) -> Vec<i32> {
        let l = nums.len();
        let r = r as usize;
        let sumlen = 1 + r * 2;

        if l < sumlen {
            vec![-1; l]
        } else {
            let mut res = vec![-1; l];

            let mut cnt = 0;
            let mut radsum = 0u64;

            for i in 0..l {
                radsum += nums[i] as u64;
                cnt += 1;

                if cnt > sumlen {
                    radsum -= nums[i - sumlen] as u64;
                    cnt -= 1;
                }
                if cnt == sumlen {
                    res[i - r] = (radsum / sumlen as u64) as i32;
                }
            }

            res
        }
    }
    pub fn get_averages_iter(nums: Vec<i32>, r: i32) -> Vec<i32> {
        let l = nums.len();
        let r = r as usize;
        let sumlen = 1 + r * 2;

        if l < sumlen {
            vec![-1; l]
        } else {
            use std::iter;

            let it_add = nums.iter();
            let it_sub = iter::repeat(&0).take(sumlen).chain(it_add.clone());
            let miter = it_add.zip(it_sub);

            let it_sums = miter.scan((0u64, 1), |(radsum, cnt), (add, sub)| {
                *radsum -= *sub as u64;
                *radsum += *add as u64;

                if *cnt < sumlen {
                    *cnt += 1;
                    Some(-1)
                } else {
                    Some((*radsum / sumlen as u64) as i32)
                }
            });

            let it_front = it_sums.skip(r);
            let it_rest = iter::repeat(-1).take(r);
            let it_all = it_front.chain(it_rest);

            it_all.collect()
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn target_indices_typical() {
        let nums = vec![7, 4, 3, 9, 1, 8, 5, 2, 6];
        let k = 3;
        let expected: Vec<i32> = vec![-1, -1, -1, 5, 4, 4, -1, -1, -1];
        assert_eq!(expected, Solution::get_averages(nums, k));

        let nums = vec![100000];
        let k = 0;
        let expected: Vec<i32> = vec![100000];
        assert_eq!(expected, Solution::get_averages(nums, k));

        let nums = vec![8];
        let k = 100000;
        let expected: Vec<i32> = vec![-1];
        assert_eq!(expected, Solution::get_averages(nums, k));
    }

    #[test]
    fn target_indices_largenumber() {
        use std::iter::repeat;
        let it_expected = repeat(-1)
            .take(40000)
            .chain(repeat(100000).take(20000))
            .chain(repeat(-1).take(40000));

        let nums = vec![100000; 100000];
        let k = 40000;
        let expected: Vec<i32> = it_expected.collect();
        assert_eq!(expected, Solution::get_averages(nums, k));
    }

    #[test]
    fn target_indices_iter_typical() {
        let nums = vec![7, 4, 3, 9, 1, 8, 5, 2, 6];
        let k = 3;
        let expected: Vec<i32> = vec![-1, -1, -1, 5, 4, 4, -1, -1, -1];
        assert_eq!(expected, Solution::get_averages_iter(nums, k));

        let nums = vec![100000];
        let k = 0;
        let expected: Vec<i32> = vec![100000];
        assert_eq!(expected, Solution::get_averages_iter(nums, k));

        let nums = vec![8];
        let k = 100000;
        let expected: Vec<i32> = vec![-1];
        assert_eq!(expected, Solution::get_averages_iter(nums, k));
    }

    #[test]
    fn target_indices_iter_largenumber() {
        use std::iter::repeat;
        let it_expected = repeat(-1)
            .take(40000)
            .chain(repeat(100000).take(20000))
            .chain(repeat(-1).take(40000));

        let nums = vec![100000; 100000];
        let k = 40000;
        let expected: Vec<i32> = it_expected.collect();
        assert_eq!(expected, Solution::get_averages_iter(nums, k));
    }
}
