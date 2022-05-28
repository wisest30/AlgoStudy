impl Solution {
    pub fn total_strength(strength: Vec<i32>) -> i32 {
        let strength = strength.into_iter().map(|x| x as i64).collect::<Vec<_>>();
        let m = 1_000_000_007i64;
        let n = strength.len();
        let mut left = vec![0usize; n];
        let mut right = vec![n; n];
        
        let mut st = Vec::new();
        for i in 0..n {
            while !st.is_empty() && strength[*st.last().unwrap()] > strength[i] {
                right[*st.last().unwrap()] = i;
                st.pop();
            }
            
            if !st.is_empty() {
                left[i] = *st.last().unwrap() + 1;
            }
            
            st.push(i);
        }
        
        let mut ps = vec![0i64; n + 1];
        let mut ips = vec![0i64; n + 1];
        for i in 1..=n {
            ps[i] = (ps[i-1] + strength[i-1]) % m;
            ips[i] = (ips[i-1] + i as i64 * strength[i-1]) % m;
        }
        
        let ret = (0..n).map(|i| {
            let ls = (ips[i+1] - ips[left[i]] - left[i] as i64 * (ps[i+1] - ps[left[i]])) % m;
            let rs = -(ips[right[i]] - ips[i+1] - (right[i] as i64 + 1) * (ps[right[i]] - ps[i+1])) % m;
            let mut ts = ls * (right[i] - i) as i64 % m + rs * (i - left[i] + 1) as i64 % m;
            
            if ts < 0 {
                ts = ts + m
            }
            
            ts * strength[i] % m
        }).sum::<i64>() % m;
        ret as i32
    }
}
