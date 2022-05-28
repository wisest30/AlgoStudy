impl Solution {
    pub fn maximum_bags(capacity: Vec<i32>, rocks: Vec<i32>, mut additional_rocks: i32) -> i32 {
        let mut v = (0..capacity.len()).map(|i| capacity[i] - rocks[i]).collect::<Vec<_>>();
        v.sort();
        
        let mut ret = 0;
        for x in v {
            if x <= additional_rocks {
                additional_rocks -= x;
                ret += 1;
            } else {
                break;
            }
        }
        
        ret
    }
}
