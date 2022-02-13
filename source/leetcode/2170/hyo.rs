impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        fn get_1st_and_2st_frequency<'a>(mut it : impl Iterator<Item = &'a i32>) -> Vec<(i32, i32)> {
            let mut counter = std::collections::HashMap::new();
            let mut ret = vec![(0, 0), (0, 0)];
            while let Some(&val) = it.next() {
                let e = counter.entry(val).or_insert(0);
                *e += 1;
                
                if *e > ret[0].1 {
                    if ret[0].0 != val {
                        ret[1] = ret[0];
                    }
                    
                    ret[0] = (val, *e);
                } else if *e > ret[1].1 {
                    ret[1] = (val, *e);
                }
            }
            
            ret
        }
        
        if nums.len() == 1 {
            0
        } else {
            let even = get_1st_and_2st_frequency(nums.iter().step_by(2));
            let odd = get_1st_and_2st_frequency(nums.iter().skip(1).step_by(2));
            let mut ret = nums.len() as i32 - std::cmp::max(even[0].1, odd[0].1);
            for e in &even {
                for o in &odd {
                    if e.0 != o.0 {
                        ret = std::cmp::min(ret, nums.len() as i32 - e.1 - o.1);
                    }
                }
            }
            
            ret
        }
    }
}
