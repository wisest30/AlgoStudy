impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        operations
            .iter()
            .map(|x| match x.find('+') {
                Some(_) => 1,
                None => -1,
            })
            .sum()
    }
}
