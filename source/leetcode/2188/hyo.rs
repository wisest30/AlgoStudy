impl Solution {
    pub fn minimum_finish_time(tires: Vec<Vec<i32>>, change_time: i32, num_laps: i32) -> i32 {
        let change_time = change_time as i64;
        let num_laps = num_laps as i64;
        let mut cost = vec![i64::MAX; 20];
        for i in 1..cost.len() {
            cost[i] = (change_time + tires[0][0] as i64) * i as i64;
        }
        for t in &tires {
            let mut s = change_time;
            let mut r = 1i64;
            for i in 1..cost.len() {
                s += t[0] as i64 * r;
                cost[i] = std::cmp::min(cost[i], s);
                r = r * t[1] as i64;
                if t[0] as i64 * r > change_time + t[0] as i64 {
                    break;
                }
            }
        }
        
        let mut dp = vec![i64::MAX; num_laps as usize + 1];
        dp[0] = 0;
        for i in 1..cost.len() {
            for j in i..dp.len() {
                dp[j] = std::cmp::min(dp[j], dp[j - i] + cost[i]);
            }
        }
        
        (*dp.last().unwrap() - change_time) as i32
    }
}
