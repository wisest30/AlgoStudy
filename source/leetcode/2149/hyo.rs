impl Solution {
    pub fn rearrange_array(nums: Vec<i32>) -> Vec<i32> {
        let minus = nums.iter().filter(|x| x.is_negative());
        let plus = nums.iter().filter(|x| x.is_positive());
        
        let mut ret = Vec::with_capacity(nums.len());
        for (&p, &m) in plus.zip(minus) {
            ret.push(p);
            ret.push(m);
        }
        ret
    }
}
