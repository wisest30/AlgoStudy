use std::collections::HashSet;

impl Solution {
    pub fn shortest_sequence(rolls: Vec<i32>, k: i32) -> i32 {
        let mut ret = 1;
        let mut set = HashSet::new();
        for x in rolls {
            set.insert(x);
            if set.len() == k as usize {
                ret += 1;
                set.clear();
            }
        }

        ret
    }
}
