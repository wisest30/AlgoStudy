impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut cnt = 0i64;
        let mut ret = 0i64;

        for num in nums {
            cnt = if num == 0 { cnt + 1 } else { 0 };
            ret += cnt;
        }

        ret
    }
}
