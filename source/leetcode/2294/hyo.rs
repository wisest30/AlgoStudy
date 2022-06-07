impl Solution {
    pub fn partition_array(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let mut sub = Vec::new();
        let mut ret = 0;
        for num in nums {
            if !sub.is_empty() && num - sub[0] <= k {
                sub.push(num)
            } else {
                sub = vec![num];
                ret += 1;
            }
        }
        
        ret
    }
}
