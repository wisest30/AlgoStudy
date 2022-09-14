impl Solution {
    pub fn partition_string(s: String) -> i32 {
        use std::collections::HashSet;
        let mut set = HashSet::new();
        let mut ret = 1;
        for c in s.chars() {
            if set.contains(&c) {
                ret += 1;
                set.clear();
            }
            
            set.insert(c);
        }

        ret
    }
}
