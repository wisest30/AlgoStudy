use std::collections::HashSet;

impl Solution {
    pub fn count_excellent_pairs(nums: Vec<i32>, k: i32) -> i64 {
        let nums = nums.into_iter().collect::<HashSet<_>>();
        let mut v = vec![0i64; 61];
        for num in nums {
            v[num.count_ones() as usize] += 1;
        }

        let mut ret = 0i64;
        for i in 0..v.len() {
            for j in 0..v.len() {
                if i + j >= k as usize {
                    ret += v[i] * v[j];
                }
            }
        }

        ret
    }
}
