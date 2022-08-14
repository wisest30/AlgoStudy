use std::collections::HashMap;
impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut ret = n as i64 * (n as i64 - 1) / 2;
        let mut map = HashMap::new();
        for (i, val) in nums.into_iter().enumerate() {
            let e = map.entry(i as i32 - val).or_insert(0);
            ret -= *e;
            *e += 1;
        }

        ret
    }
}
