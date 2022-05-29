impl Solution {
    pub fn maximum_importance(n: i32, roads: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut degree = vec![0; n];
        for road in roads {
            degree[road[0] as usize] += 1;
            degree[road[1] as usize] += 1;
        }
        
        degree.sort_unstable();
        (1..=n).map(|i| i as i64 * degree[i - 1]).sum::<i64>()
    }
}
