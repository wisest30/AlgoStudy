impl Solution {
    pub fn maximums_spliced_array(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        use std::cmp::{min, max};
        
        pub fn f(nums1: &Vec<i32>, nums2: &Vec<i32>) -> i32 {
            let n = nums1.len();
            let mut arr = vec![0; n];
            
            for i in 0..n {
                arr[i] = nums2[i] - nums1[i];
            }
            
            
            let mut ps = vec![0; n+1];
            for i in 1..=n {
                ps[i] = ps[i-1] + arr[i-1];
            }
            
            let mut ret = 0;
            let mut min_val = 0;
            for i in 1..=n {
                ret = max(ret, ps[i] - min_val);
                min_val = min(min_val, ps[i]);
            }
            
            ret += nums1.iter().sum::<i32>();
            
            ret
        }
        
        max(f(&nums1, &nums2), f(&nums2, &nums1))
    }
}
