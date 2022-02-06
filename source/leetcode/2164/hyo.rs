impl Solution {
    pub fn sort_even_odd(nums: Vec<i32>) -> Vec<i32> {
        let mut even = nums.iter().step_by(2).map(|&x| x).collect::<Vec<i32>>();
        even.sort();
        
        let mut odd = nums.iter().skip(1).step_by(2).map(|&x| x).collect::<Vec<i32>>();
        odd.sort_by_key(|&x| -x);
        
        let mut ret = vec![0; nums.len()];
        for i in 0..ret.len() {
            ret[i] = if i % 2 == 0 { even[i / 2] } else { odd[i / 2] };
        }
        
        ret
    }
}
