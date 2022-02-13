impl Solution {
    pub fn minimum_removal(mut beans: Vec<i32>) -> i64 {
        beans.sort();
        let n = beans.len();
        let mut sum = 0i64;
        let mut max_val = 0i64;
        for (i, val) in beans.into_iter().enumerate() {
            sum += val as i64;
            max_val = std::cmp::max(max_val, val as i64 * (n - i) as i64);
        }
        sum - max_val
    }
}
