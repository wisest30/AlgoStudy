impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let n = nums.len();
        let mut ret = 0;
        for i in 0..n {
            for j in i + 1..n {
                for k in j + 1..n {
                    if nums[j] - nums[i] == diff && nums[k] - nums[j] == diff {
                        ret += 1;
                    }
                }
            }
        }

        ret
    }
}
