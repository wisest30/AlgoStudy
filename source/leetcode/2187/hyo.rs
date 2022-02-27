impl Solution {
    pub fn minimum_time(time: Vec<i32>, total_trips: i32) -> i64 {
        let total_trips = total_trips as i64;
        let mut l = 0i64;
        let mut r = 1_000_000_000_000_000i64;
        while l + 1 < r {
            let mut m = (l + r) / 2;
            if time.iter().fold(0i64, |acc, &x| std::cmp::min(total_trips, acc + m / x as i64)) >= total_trips {
                r = m;
            } else {
                l = m;
            }
        }
        r
    }
}
