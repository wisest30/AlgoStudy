impl Solution {
    pub fn gcd(a: usize, b: usize) -> usize {
        if b == 0 {
            a
        } else {
            Solution::gcd(b, a % b)
        }
    }
    
    pub fn distinct_sequences(n: i32) -> i32 {
        if n == 1 {
            6
        } else {
            let mo = 1_000_000_007;
            let mut dp = vec![vec![0i64; 7]; 7];
            for i in 1..=6 {
                for j in 1..=6 {
                    dp[i][j] = if i != j && Solution::gcd(i, j) == 1 {
                        1
                    } else {
                        0
                    };
                }
            }
            
            for _ in 0..n-2 {
                let mut ndp = vec![vec![0i64; 7]; 7];
                for i in 1..=6 {
                    for j in 1..=6 {
                        for k in 1..=6 {
                            if i != k && j != k && Solution::gcd(j, k) == 1 {
                                ndp[j][k] += dp[i][j];
                                ndp[j][k] %= mo;
                            }
                        }
                    }
                }
                
                dp = ndp;
            }
            
            let mut ret = 0i64;
            for i in 1..=6 {
                for j in 1..=6 {
                    ret += dp[i][j];
                    ret %= mo;
                }
            }
            
            ret as i32
        }
    }
}
