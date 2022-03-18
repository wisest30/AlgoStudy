impl Solution {
    pub fn maximum_top(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let n = nums.len();
        
        if k == 0 { nums[0] }
        else if n == 1 { if k % 2 == 1 { -1 } else { nums[0] } }
        else if k == 1 { nums[1] }
        else if k < n { std::cmp::max(*nums.iter().take(k-1).max().unwrap(), nums[k]) }
        else if k == n { nums.into_iter().take(n-1).max().unwrap() }
        else { nums.into_iter().max().unwrap() }
    }
}
