impl Solution {
    pub fn minimum_lines(mut stock_prices: Vec<Vec<i32>>) -> i32 {
        let n = stock_prices.len();
        if n == 1 {
            return 0;
        }

        stock_prices.sort_unstable();
        let break_count = (1..n-1).filter(|&i| {
                let dx0 = stock_prices[i][0] - stock_prices[i-1][0];
                let dy0 = stock_prices[i][1] - stock_prices[i-1][1];
                let dx1 = stock_prices[i+1][0] - stock_prices[i][0];
                let dy1 = stock_prices[i+1][1] - stock_prices[i][1];
                dx0 as i64 * dy1 as i64 != dy0 as i64 * dx1 as i64
            }).count();
        
        1 + break_count as i32
    }
}
