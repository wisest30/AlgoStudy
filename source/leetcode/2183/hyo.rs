impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i64 {
        fn gcd(x: i32, y: i32) -> i32 {
            if y == 0 {
                x
            } else {
                gcd(y, x % y)
            }
        }
        
        let divs = (1..=k).filter(|x| k % x == 0).collect::<Vec<i32>>();
        let mut counter = std::collections::HashMap::new();
        for div in divs {
            counter.insert(div, nums.iter().filter(|&x| x % div == 0).count());
        }
        
        let mut ret = 0i64;
        for num in nums {
            let p = k / gcd(num, k);
            if let Some(&add) = counter.get(&p) {
                ret += add as i64;
                if num % p == 0 {
                    ret -= 1;
                }
            }
        }
        
        ret /= 2;
        ret
    }
}
