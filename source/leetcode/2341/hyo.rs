use std::collections::HashMap;

impl Solution {
    pub fn number_of_pairs(nums: Vec<i32>) -> Vec<i32> {
        let mut map = HashMap::new();
        let mut ret = vec![0, 0];

        for num in nums {
            *map.entry(num).or_insert(0) += 1;
        }

        for cnt in map.into_values() {
            ret[0] += cnt / 2;
            ret[1] += cnt % 2;
        }

        ret
    }
}
