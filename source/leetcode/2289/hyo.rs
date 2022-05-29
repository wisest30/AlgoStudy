impl Solution {
    pub fn total_steps(nums: Vec<i32>) -> i32 {
        use std::cmp::max;
        
        let n = nums.len();
        let mut st = Vec::<(usize, usize)>::new();
        let mut max_val = 0;
        let mut ret = 0;
        for i in 0..n {
            if nums[i] >= max_val {
                st.clear();
                st.push((i, 0));
                max_val = nums[i];
            } else {
                let mut max_cnt = 0;
                while !st.is_empty() && nums[st.last().unwrap().0] <= nums[i] {
                    max_cnt = max(max_cnt, st.pop().unwrap().1);
                }
                
                st.push((i, max_cnt + 1));
                ret = max(ret, max_cnt + 1);
            }
        }
        
        ret as i32
    }
}
