impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let mut ret = 1;
        let n = nums.len();

        for i in 0..n {
            let mut x = 0;
            let mut len = 0;
            for j in i..n {
                if (x & nums[j]) != 0 {
                    break;
                }

                x |= nums[j];
                len += 1;
            }

            ret = std::cmp::max(ret, len);
        }

        ret
    }
}
