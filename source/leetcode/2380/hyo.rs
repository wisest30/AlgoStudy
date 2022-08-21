impl Solution {
    pub fn seconds_to_remove_occurrences(mut s: String) -> i32 {
        let mut ret = 0;
        while s.find("01").is_some() {
            ret += 1;

            s = s.replace("01", "10");
        }

        ret
    }
}
