impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let max_val = |i: usize, j: usize| {
            let mut ret = 0i32;
            for k in 0..3 {
                for l in 0..3 {
                    ret = std::cmp::max(ret, grid[i + k][j + l]);
                }
            }

            ret
        };

        let n = grid.len();
        let mut ret = vec![vec![0; n - 2]; n - 2];

        for i in 0..n - 2 {
            for j in 0..n - 2 {
                ret[i][j] = max_val(i, j);
            }
        }

        ret
    }
}
