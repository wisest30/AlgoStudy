impl Solution {
    pub fn k_increasing(arr: Vec<i32>, k: i32) -> i32 {
        use std::cmp::Ordering::{Less, Greater};
        let lis_len = move |arr| {
            let mut tmp = Vec::new();
            for e in arr {
                let p = tmp.binary_search_by(|&x| if x <= e { Less } else { Greater }).unwrap_or_else(|i| i);
                if p < tmp.len() {
                    tmp[p] = e;
                } else {
                    tmp.push(e);
                }
            }
            tmp.len() as i32
        };
        
        let k = k as usize;
        let mut ret = 0;
        for i in 0..k {
            let a = arr.iter().skip(i).step_by(k).collect::<Vec<_>>();
            ret += a.len() as i32 - lis_len(a);
        }
        
        ret
    }
}
