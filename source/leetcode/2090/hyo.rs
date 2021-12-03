impl Solution {
    pub fn get_averages(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let nums = nums.iter().map(|x| *x as i64).collect::<Vec<i64>>();
        let k = k as usize;
        let n = nums.len();
        
        let mut ret = vec![-1; n];
        let mut sum = 0;
        for (i, &v) in nums.iter().enumerate() {
            sum += v;
            if i >= 2 * k {
                ret[i - k] = sum / (2 * k as i64 + 1);
                sum -= nums[i - 2 * k];
            }
        }
        
        ret.iter().map(|x| *x as i32).collect::<Vec<i32>>()
    }
}
