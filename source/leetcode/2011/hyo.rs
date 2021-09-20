impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut ret = 0;
        for op in operations {
            for c in op.chars() {
                if c == '-' {
                    ret -= 1;
                    break;
                } else if c == '+' {
                    ret += 1;
                    break;
                }
            }
        }
        
        ret
    }
}
