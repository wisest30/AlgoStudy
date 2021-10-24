impl Solution {
    fn check(mut n: i32) -> bool {
        let mut cnt = vec![0; 10];
        while n > 0 {
            cnt[(n % 10) as usize] += 1;
            n /= 10;
        }
        
        for i in 0..10 {
            if cnt[i] > 0 && cnt[i] != i {
                return false;
            }
        }
        
        true
    }
    
    pub fn next_beautiful_number(n: i32) -> i32 {
        let mut ret = n;
        loop {
            ret += 1;
            if Solution::check(ret) {
                break;
            }
        }
        
        ret
    }
}
