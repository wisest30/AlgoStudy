impl Solution {
    pub fn k_sum(nums: Vec<i32>, k: i32) -> i64 {
        let pos_sum = nums
            .iter()
            .map(|&num| num as i64)
            .filter(|&x| x > 0)
            .sum::<i64>();

        let mut nums = nums
            .into_iter()
            .map(|num| num.abs() as i64)
            .collect::<Vec<_>>();

        let k = k as usize;
        nums.sort_unstable();
        if nums.len() > k {
            nums.resize(k, 0);
        }

        let mut all_sum = vec![0i64];
        for num in nums {
            for i in 0..all_sum.len() {
                all_sum.push(num + all_sum[i]);
            }

            all_sum.sort_unstable();

            if all_sum.len() > k {
                all_sum.resize(k, 0);
            }
        }

        pos_sum - all_sum[k - 1]
    }
}
