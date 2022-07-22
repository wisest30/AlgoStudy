use std::cmp::max;
use std::collections::HashMap;
impl Solution {
    pub fn maximum_sum(nums: Vec<i32>) -> i32 {
        fn digit_sum(mut num: i32) -> i32 {
            let mut ret = 0;
            while num > 0 {
                ret += num % 10;
                num /= 10;
            }

            ret
        }

        let mut ret = -1;
        let mut map = HashMap::new();
        for num in nums {
            let key = digit_sum(num);
            if let Some(&max_val) = map.get(&key) {
                ret = max(ret, max_val + num);
                if num > max_val {
                    map.insert(key, num);
                }
            } else {
                map.insert(key, num);
            }
        }

        ret
    }
}
