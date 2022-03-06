impl Solution {
    pub fn replace_non_coprimes(nums: Vec<i32>) -> Vec<i32> {
        fn gcd(a: i32, b: i32) -> i32 {
            if b == 0 { a } else { gcd(b, a % b) }
        }
        
        let mut ret = Vec::new();
        
        for num in nums {
            ret.push(num);
            
            while ret.len() > 1 {
                let a = ret.pop().unwrap();
                let b = ret.pop().unwrap();
                let g = gcd(a, b);
                if g > 1 {
                    ret.push((a as i64 * b as i64 / g as i64) as i32);
                } else {
                    ret.push(b);
                    ret.push(a);
                    break;
                }
            }
        }
        
        ret
    }
}
