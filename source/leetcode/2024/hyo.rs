impl Solution {
    pub fn max_consecutive_answers(answer_key: String, k: i32) -> i32 {
        let answer_key = answer_key.chars().collect::<Vec<_>>();
        let n = answer_key.len();
        let mut tsum = vec![0];
        let mut fsum = vec![0];
        for i in 0..n {
            tsum.push(tsum[i] + if answer_key[i] == 'T' { 1 } else { 0 });
            fsum.push(fsum[i] + if answer_key[i] == 'F' { 1 } else { 0 });
        }
        
        let mut l = 0;
        let mut r = n + 1;
        while l + 1 < r {
            let m = (l + r) / 2;
            
            let mut check = false;
            for i in 0..=n-m {
                if tsum[i + m] - tsum[i] <= k
                || fsum[i + m] - fsum[i] <= k {
                    check = true;
                    break;
                }
            }
            
            if check {
                l = m;
            } else {
                r = m;
            }
        }
        
        l as i32
    }
}
