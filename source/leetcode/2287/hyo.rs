impl Solution {
    pub fn rearrange_characters(s: String, target: String) -> i32 {
        use std::collections::HashMap;
        
        let mut smap = HashMap::new();
        for c in s.chars() {
            *smap.entry(c).or_insert(0) += 1;
        }
        
        let mut tmap = HashMap::new();
        for c in target.chars() {
            *tmap.entry(c).or_insert(0) += 1;
        }
        
        tmap.into_iter().map(|x| *smap.entry(x.0).or_insert(0) / x.1).min().unwrap() as i32
    }
}
