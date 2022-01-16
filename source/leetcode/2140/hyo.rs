impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        use std::cmp::max;
        
        fn max_point_from(start_idx : usize, questions: &Vec<Vec<i32>>, dp: &Vec<i64>) -> i64 {
            let nxt_idx = start_idx + 1 + questions[start_idx][1] as usize;
            questions[start_idx][0] as i64 + if nxt_idx < dp.len() { dp[nxt_idx] } else { 0 }
        }
        // dp[i] is maximum value of {max_point_from(i), max_point_from(i+1), max_point_from(i+2) ... max_point_from(n-1)}
        fn cacluate_dp(start_idx : usize, questions: &Vec<Vec<i32>>, dp: &Vec<i64>) -> i64 {
            if start_idx + 1 < dp.len() {
                max(max_point_from(start_idx, questions, dp), dp[start_idx + 1])
            } else {
                max_point_from(start_idx, questions, dp)
            }
        }
        
        let n = questions.len();
        let mut dp = vec![0i64; n];
        for i in (0..n).rev() { dp[i] = cacluate_dp(i, &questions, &dp); }
        dp[0]
    }
}
