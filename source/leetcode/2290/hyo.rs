impl Solution {
    pub fn minimum_obstacles(grid: Vec<Vec<i32>>) -> i32 {
        use std::collections::BinaryHeap;
        
        let dy = [-1, 0, 0, 1];
        let dx = [0, -1, 1, 0];
        
        let r = grid.len();
        let c = grid[0].len();
        
        let mut visited = vec![vec![false; c]; r];
        let mut q = BinaryHeap::new();
        q.push((0i32, 0i32, 0i32));
        while !q.is_empty() {
            let d = -q.peek().unwrap().0;
            let y = q.peek().unwrap().1;
            let x = q.peek().unwrap().2;
            q.pop();
            
            if visited[y as usize][x as usize] {
                continue;
            }
            visited[y as usize][x as usize] = true;
            
            if y == r as i32 - 1 && x == c as i32 - 1 {
                return d;
            }
            
            for i in 0..4 {
                let ny = y + dy[i];
                let nx = x + dx[i];
                
                if ny < 0 || ny >= r as i32 || nx < 0 || nx >= c as i32 {
                    continue;
                }
                
                q.push((-(d + grid[ny as usize][nx as usize]), ny, nx));
            }
        }
        
        panic!();
    }
}
