use std::collections::BTreeMap;
impl Solution {
    pub fn merge_similar_items(
        mut items1: Vec<Vec<i32>>,
        mut items2: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        let mut map = BTreeMap::new();
        for item in items1 {
            map.insert(item[0], item[1]);
        }
        for item in items2 {
            *map.entry(item[0]).or_insert(0) += item[1];
        }

        map.into_iter()
            .map(|item| vec![item.0, item.1])
            .collect::<Vec<_>>()
    }
}
