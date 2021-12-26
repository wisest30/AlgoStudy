impl Solution {
    pub fn recover_array(nums: Vec<i32>) -> Vec<i32> {
        use std::collections::{HashSet, BTreeMap};
        
        let mut ks = HashSet::new();
        let min_num = *nums.iter().min().unwrap();
        nums.iter().for_each(|&x|
            if x > min_num && x % 2 == min_num % 2 {
                ks.insert((x - min_num) / 2);
            }
        );
        
        let mut counter = BTreeMap::new();
        for num in nums {
            let e = counter.entry(num).or_insert(0);
            *e += 1;
        }
        let keys = counter.keys().map(|&x| x).collect::<Vec<i32>>();
        for k in ks {
            let mut ret = Vec::new();
            let mut valid = true;
            let mut counter_clone = counter.clone();
            for key in &keys {
                let val = *counter_clone.get(key).unwrap();
                let e = counter_clone.entry(key + 2 * k).or_insert(0);
                if *e < val {
                    valid = false;
                    break;
                }
                
                *e -= val;
                ret.extend(vec![key + k; val]);
            }
            
            if valid {
                return ret;
            }
        }
        
        panic!();
    }
}
