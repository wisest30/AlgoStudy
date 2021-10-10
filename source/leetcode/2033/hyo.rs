use std::collections::HashSet;
impl Solution {
    pub fn min_operations(grid: Vec<Vec<i32>>, x: i32) -> i32 {
        let mut A = grid.into_iter().flatten().collect::<Vec<_>>();
        A.sort();
        
        let cnt = A.iter().map(|&y| y % x).collect::<HashSet<_>>().len();
        if cnt != 1 {
            -1
        } else {
            let val = A[A.len() / 2];
            A.into_iter().map(|y| (val - y).abs() / x).sum()
        }
    }
}
