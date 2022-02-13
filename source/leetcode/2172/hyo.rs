impl Solution {
    pub fn maximum_and_sum(nums: Vec<i32>, num_slots: i32) -> i32 {
        let num_slots = num_slots as usize;
        let mut max_subset = 3usize.pow(num_slots as u32);
        let mut dp = vec![0; max_subset];
        for i in 0..nums.len() {
            let mut ndp = vec![0; max_subset];
            for subset in 0..max_subset {
                let mut p = 1usize;
                for j in 0..num_slots {
                    let cnt = subset / p % 3;
                    if cnt < 2 {
                        ndp[subset + p] = std::cmp::max(ndp[subset + p], dp[subset] + (nums[i] & (j + 1) as i32));
                    }
                    p *= 3;
                }
            }
            
            dp = ndp;
        }
        
        dp.into_iter().max().unwrap()
    }
}
