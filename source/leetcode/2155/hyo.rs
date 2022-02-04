impl Solution {
    pub fn max_score_indices(nums: Vec<i32>) -> Vec<i32> {
        let mut cnts = [0, nums.iter().filter(|&&x| x == 1).count()];        
        let n = nums.len();
        let mut max_score = 0;
        let mut ret = Vec::new();
        for i in 0..=n {
            let score = cnts[0] + cnts[1];
            if score == max_score {
                ret.push(i as i32);
            } else if score > max_score {
                max_score = score;
                ret = vec![i as i32];
            }
            
            if i < n {
                cnts[0] += nums[i] as usize ^ 1;
                cnts[1] -= nums[i] as usize;
            }
        }
        
        ret
    }
}
