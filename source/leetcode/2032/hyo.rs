impl Solution {
    pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32> {
        let mut A = vec![0usize; 101];
        for num in nums1 { A[num as usize] |= 1; }
        for num in nums2 { A[num as usize] |= 2; }
        for num in nums3 { A[num as usize] |= 4; }
        
        (0..=100).filter(|&x| A[x as usize].count_ones() >= 2).collect::<_>()
    }
}
