impl Solution {
    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        fn recursive(n: usize, mut batteries: Vec<i64>, sum: i64) -> i64 {
            let last = batteries.pop().unwrap();
            if last > sum / n as i64 {
                recursive(n-1, batteries, sum - last)
            } else {
                sum / n as i64
            }
        }
        
        let n = n as usize;
        let mut batteries = batteries.iter().map(|&x| x as i64).collect::<Vec<_>>();
        batteries.sort();
        let sum = batteries.iter().sum();
        recursive(n, batteries, sum)
    }
}
