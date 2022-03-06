impl Solution {
    pub fn minimal_k_sum(mut nums: Vec<i32>, k: i32) -> i64 {
        nums.sort();
        nums.push(i32::MAX);
        
        let mut ret = 0i64;
        let mut prev = 0i32;
        let mut k = k as i64;
        for &cur in &nums {
            if prev != cur {
                let cnt = std::cmp::min((cur - prev - 1) as i64, k);
                let p = prev as i64;
                
                ret += (p + cnt) * (p + cnt + 1) / 2 - p * (p + 1) / 2;
                k -= cnt;
                
                prev = cur;
            }
        }
        
        ret
    }
}
