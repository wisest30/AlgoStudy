impl Solution {
    pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;

        let mut map = HashMap::new();
        for num in nums {
            if num % 2 == 0 {
                *map.entry(num).or_insert(0) += 1;
            }
        }

        if let Some((_, k)) = map.into_iter().map(|(key, val)| (val, -key)).max() {
            -k
        } else {
            -1
        }
    }
}
