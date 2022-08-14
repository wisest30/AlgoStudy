use std::collections::HashMap;
impl Solution {
    pub fn task_scheduler_ii(tasks: Vec<i32>, space: i32) -> i64 {
        let mut map = HashMap::new();
        let mut cur = 1;
        for task in tasks {
            let t = task as i64;

            if map.contains_key(&t) {
                let gap = cur - map.get(&t).unwrap() - 1;
                if gap < space as i64 {
                    cur += space as i64 - gap;
                }
            }

            map.insert(t, cur);
            cur += 1;
        }

        cur - 1
    }
}
