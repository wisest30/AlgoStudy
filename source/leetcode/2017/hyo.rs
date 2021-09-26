use std::cmp::{min, max};
impl Solution {
    pub fn grid_game(grid: Vec<Vec<i32>>) -> i64 {
        let n = grid[0].len();
        let mut A = vec![0i64; n];
        let mut B = vec![0i64; n];
        
        for i in 0..n {
            A[n - 1 - i] = grid[0][n - 1 - i] as i64 + if i > 0 { A[n - i] } else { 0 };
            B[i] = grid[1][i] as i64 + if i > 0 { B[i - 1] } else { 0 };
        }
        
        let mut ret = A[0] + B[n-1];
        for i in 0..n {
            ret = min(ret, max(A[i] - grid[0][i] as i64, B[i] - grid[1][i] as i64));
        }
        
        return ret;
    }
}
