use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn best_hand(ranks: Vec<i32>, suits: Vec<char>) -> String {
        if suits.into_iter().collect::<HashSet<_>>().len() == 1 {
            return "Flush".to_string();
        }

        let mut map = HashMap::new();
        for rank in ranks.into_iter() {
            *map.entry(rank).or_insert(0) += 1;
        }

        let cnt = *map.values().max().unwrap();
        if cnt >= 3 {
            "Three of a Kind".to_string()
        } else if cnt == 2 {
            "Pair".to_string()
        } else {
            "High Card".to_string()
        }
    }
}
