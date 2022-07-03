impl Solution {
    pub fn count_paths(grid: Vec<Vec<i32>>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let r = grid.len();
        let c = grid[0].len();
        let mut dp = vec![vec![0i64; c]; r];
        let mut orders = Vec::new();
        for y in 0..r {
            for x in 0..c {
                orders.push((-grid[y][x], y, x));
            }
        }

        orders.sort_unstable();

        let dy = [-1, 0, 0, 1];
        let dx = [0, -1, 1, 0];
        let mut ret = 0i64;
        for o in orders {
            let (_, y, x) = o;
            dp[y][x] = 1;

            for i in 0..4 {
                let ny = y as i32 + dy[i];
                let nx = x as i32 + dx[i];
                if ny < 0
                    || ny >= r as i32
                    || nx < 0
                    || nx >= c as i32
                    || grid[y][x] >= grid[ny as usize][nx as usize]
                {
                    continue;
                }

                dp[y][x] = (dp[y][x] + dp[ny as usize][nx as usize]) % MOD;
            }

            ret = (ret + dp[y][x]) % MOD;
        }

        ret as i32
    }
}
