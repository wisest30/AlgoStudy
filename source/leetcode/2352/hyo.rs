impl Solution {
    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut ret = 0;
        for i in 0..n {
            for j in 0..n {
                for k in 0..n {
                    if grid[i][k] != grid[k][j] {
                        break;
                    } else if k == n - 1 {
                        ret += 1;
                    }
                }
            }
        }

        ret
    }
}
