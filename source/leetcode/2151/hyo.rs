impl Solution {
    pub fn maximum_good(statements: Vec<Vec<i32>>) -> i32 {
        let n = statements.len();
        
        let check_ith_statements = |subset, i| {
            let ith_statements : &Vec<i32> = &statements[i];
            (0..n).all(|j| match ith_statements[j] {
                0 => (subset & (1 << j)) == 0,
                1 => (subset & (1 << j)) > 0,
                _ => true
            })
        };

        let check_subset = |subset| {
            (0..n)
            .filter(|i| (subset & (1 << i)) > 0)
            .all(|i| check_ith_statements(subset, i))
        };
        
        (0..1<<n)
        .map(|subset|
            if check_subset(subset) {
                (subset as usize).count_ones() as i32
            } else {
                0
            }
        )
        .max()
        .unwrap()
    }
}
