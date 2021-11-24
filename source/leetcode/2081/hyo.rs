impl Solution {
    pub fn k_mirror(k: i32, n: i32) -> i64 {
        let mut ret = 0i64;
        
        let mut len = 1;
        let mut remain = n;
        let valid = |mut x| {
            let mut A = Vec::new();
            while x > 0 {
                A.push((x % k as i64) as u8);
                x /= k as i64;
            }

            (0..A.len() / 2).all(|i| A[i] == A[A.len() - 1 - i])
        };
        
        while remain > 0 {
            let nums = 
            if len == 1 {
                (1..10).collect()
            } else {
                let half_len = len / 2;
                let start = 10u32.pow(half_len - 1);
                let end = 10u32.pow(half_len);
                
                (start..end).map(|x| x.to_string())
                .map(|s| {
                    let r = s.chars().rev().collect::<String>();
                    
                    if len % 2 == 1 {
                        (0..10)
                        .map(|x| (s.clone() + &x.to_string() + &r).parse::<i64>().unwrap())
                        .collect::<Vec<i64>>()
                    } else {
                        vec![(s.clone() + &r).parse::<i64>().unwrap()]
                    }
                }).fold(Vec::new(), |mut acc, x| {
                    acc.extend(x);
                    acc
                })
            };

            for num in nums {
                if remain == 0 {
                    break;
                } else if valid(num) {
                    remain -= 1;
                    ret += num;
                }
            }

            len += 1;
        }
        
        ret
    }
}
