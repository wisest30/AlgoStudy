use std::collections::HashMap;
use std::cmp::max;
impl Solution {
    pub fn ways_to_partition(nums: Vec<i32>, k: i32) -> i32 {
        let nums = nums.iter().map(|&x| x as i64).collect::<Vec<i64>>();
        let k = k as i64;
        let n = nums.len();
        let sum = nums.iter().sum::<i64>();
        let mut lsum = nums[0];
        let mut rsum = sum - lsum;
        let mut rmap = HashMap::new();
        for i in 1..n {
            *rmap.entry(lsum - rsum).or_insert(0) += 1;
            lsum += nums[i];
            rsum -= nums[i];
        }

        let mut ret = *rmap.get(&0).unwrap_or(&0);
        let mut lmap = HashMap::new();
        lsum = 0;
        rsum = sum;
        for i in 0..n {
            let d = k - nums[i];
            let lcnt = *lmap.get(&d).unwrap_or(&0);
            let rcnt = *rmap.get(&-d).unwrap_or(&0);
            ret = max(ret, lcnt + rcnt);
            lsum += nums[i];
            rsum -= nums[i];
            *lmap.entry(lsum - rsum).or_insert(0) += 1;
            *rmap.entry(lsum - rsum).or_insert(0) -= 1;
        }
        
        ret
    }
}
