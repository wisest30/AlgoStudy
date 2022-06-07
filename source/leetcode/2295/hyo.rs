impl Solution {
    pub fn array_change(mut nums: Vec<i32>, operations: Vec<Vec<i32>>) -> Vec<i32> {
        use std::collections::HashMap;
        
        let mut map = HashMap::new();
        for i in 0..nums.len() {
            map.insert(nums[i], i);
        }
        
        for o in operations {
            if let Some(&x) = map.get(&o[0]) {
                nums[x as usize] = o[1];
                map.insert(o[1], x);
            }
        }
        
        nums
    }
}
