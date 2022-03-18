impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let k = k as usize;
        
        let mut key_idxs = (0..nums.len())
        .rev()
        .filter(|&x| nums[x] == key)
        .collect::<Vec<_>>();
        
        (0..nums.len())
        .filter(|&x| {
            while let Some(&idx) = key_idxs.last() {
                if idx + k < x {
                    key_idxs.pop();
                } else if x + k < idx {
                    return false;
                } else {
                    return true;
                }
            }
            
            false
        })
        .map(|x| x as i32)
        .collect::<Vec<_>>()
    }
}
