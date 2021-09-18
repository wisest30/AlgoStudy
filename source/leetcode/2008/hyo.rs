use std::cmp::max;
impl Solution {
    pub fn max_taxi_earnings(n: i32, mut rides: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut dp = vec![0i64; n + 2];
        
        rides.sort();
        
        let mut i = 0usize;
        let mut j = 0usize;
        let mut ret = 0;
        while i < rides.len() {
            if j < rides[i][0] as usize {
                dp[j + 1] = max(dp[j + 1], dp[j]);
                j += 1;
            } else {
                let mut val = dp[j] + (rides[i][1] - rides[i][0] + rides[i][2]) as i64;
                dp[rides[i][1] as usize] = max(dp[rides[i][1] as usize], val);
                ret = max(ret, val);
                i += 1;
            }
        }
        
        ret
    }
}
