use std::collections::HashMap;

impl Solution {
    pub fn find_original_array(changed: Vec<i32>) -> Vec<i32> {
        let mut m = HashMap::new();
        for &x in &changed {
            let p = m.entry(x).or_insert(0);
            *p += 1;
        }

        let mut ret = Vec::new();
        for i in 0..=100000 {
            while m.contains_key(&i) && *m.get(&i).unwrap() > 0 {
                let p = m.entry(i).or_insert(0);
                *p -= 1;
                
                let j = i * 2;
                if !m.contains_key(&j) || *m.get(&j).unwrap() == 0 {
                    return vec![0; 0];
                } else {
                    let q = m.entry(j).or_insert(0);
                    *q -= 1;
                    
                    ret.push(i);
                }
            }
        }
                
        ret
    }
}
