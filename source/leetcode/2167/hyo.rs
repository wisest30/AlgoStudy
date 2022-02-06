impl Solution {
    pub fn minimum_time(s: String) -> i32 {
        let s = s.chars().collect::<Vec<_>>();
        let n = s.len();
        
        let mut a = vec![0usize; n+1];        
        let mut cnt = 0usize;
        for i in 0..=n {            
            a[i] = 2 * cnt + (n - i);
            if i < n && s[i] == '1' {
                cnt += 1;
            }
        }
        
        let mut right_min_val = vec![0usize; n+1];
        right_min_val[n] = a[n];
        for i in (0..n).rev() {
            right_min_val[i] = std::cmp::min(right_min_val[i+1], a[i]);
        }
        let mut ret = right_min_val[0];
        let mut cnt = 0usize;
        for i in 1..n {
            if s[i-1] == '1' {
                cnt += 1;
            }
            
            ret = std::cmp::min(ret, right_min_val[i] + i - 2 * cnt);
        }
        ret as i32
    }
}
