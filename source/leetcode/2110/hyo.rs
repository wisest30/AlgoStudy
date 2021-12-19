impl Solution {
    pub fn get_descent_periods(prices: Vec<i32>) -> i64 {
        let mut cnt = 0i64;
        let mut ret = 0i64;
        for i in 0..prices.len() {
            cnt = 
                if i == 0 || prices[i] != prices[i-1] - 1 {
                    1
                } else {
                    cnt + 1
                };
            
            ret += cnt;
        }
        
        ret
    }
}
