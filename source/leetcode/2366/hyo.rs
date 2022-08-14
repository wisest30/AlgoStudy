impl Solution {
    pub fn minimum_replacement(mut nums: Vec<i32>) -> i64 {
        let mut ret = 0;
        let mut last = nums.pop().unwrap() as i64;
        while !nums.is_empty() {
            let l = nums.pop().unwrap() as i64;
            ret += l / last;
            if l % last == 0 {
                ret -= 1;
            } else if l < last {
                last = l;
            } else {
                let cnt = l / last + 1;
                last = l / cnt;
            }
        }
        ret
    }
}
