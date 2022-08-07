impl Solution {
    pub fn maximum_groups(grades: Vec<i32>) -> i32 {
        let mut i = 1;
        while i * (i + 1) / 2 <= grades.len() {
            i += 1;
        }

        i as i32 - 1
    }
}
