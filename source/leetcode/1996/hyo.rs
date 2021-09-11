impl Solution {
    pub fn number_of_weak_characters(mut P: Vec<Vec<i32>>) -> i32 {
        P.sort();
        
        let mut max_second = 0;
        let mut prev_max_second = 0;
        let mut ret = 0;
        for (i, x) in P.iter().enumerate().rev() {
            if i < P.len() - 1 && x[0] != P[i+1][0] {
                prev_max_second = max_second;
            }
            
            if x[1] < prev_max_second {
                ret += 1;
            }

            max_second = std::cmp::max(max_second, x[1]);
        }
        
        ret
    }
}
