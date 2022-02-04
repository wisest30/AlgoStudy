impl Solution {
    pub fn sub_str_hash(s: String, power: i32, modulo: i32, k: i32, hash_value: i32) -> String {
        let power = power as u64;
        let modulo = modulo as u64;
        let k = k as usize;
        let hash_value = hash_value as u64;
        let v = s.chars()
                 .rev()
                 .map(|c| c as u64 - 'a' as u64 + 1)
                 .collect::<Vec<_>>();

        let n = v.len();
        let mut p = 1u64;
        let mut h = 0u64;
        let mut ridx = 0;
        for i in 0..n {
            if i < k {
                h = (h * power + v[i]) % modulo;
                p = p * power % modulo
            } else {
                h = (h * power + v[i] + (modulo - p * v[i - k] % modulo)) % modulo;
            }
            
            if i >= k - 1 && h == hash_value {
                ridx = i + 1;
            }
        }

        let idx = n - ridx;
        s[idx..idx + k].to_string()
    }
}
