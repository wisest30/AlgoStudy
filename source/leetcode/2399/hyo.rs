use std::collections;
impl Solution {
    pub fn check_distances(s: String, distance: Vec<i32>) -> bool {
        let mut map = collections::HashMap::new();
        let mut v = vec![-1; 26];
        s.chars().enumerate().for_each(|(i, c)| {
            let c = c as u8 - 'a' as u8;
            if map.contains_key(&c) {
                v[c as usize] = (i - map.get(&c).unwrap() - 1) as i32;
            } else {
                map.insert(c, i);
            }
        });

        v.into_iter()
            .enumerate()
            .all(|(i, d)| d == -1 || d == distance[i])
    }
}
