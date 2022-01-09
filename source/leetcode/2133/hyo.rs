impl Solution {
    pub fn check_valid(matrix: Vec<Vec<i32>>) -> bool {
        use std::collections::HashSet;
        let n = matrix.len();
        for i in 0..n {
            let mut s1 = HashSet::new();
            let mut s2 = HashSet::new();
            for j in 0..n {
                s1.insert(matrix[i][j]);
                s2.insert(matrix[j][i]);
            }
            if s1.len() != n || s2.len() != n { return false; }
        }
        true
    }
}
