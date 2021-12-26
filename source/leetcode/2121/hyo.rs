impl Solution {
    pub fn get_distances(arr: Vec<i32>) -> Vec<i64> {
        let max_n = 100001;
        let n = arr.len();
        let mut rs = vec![0; max_n];
        let mut rc = vec![0; max_n];
        let mut ls = vec![0; max_n];
        let mut lc = vec![0; max_n];
        
        for (i, &v) in arr.iter().enumerate() {
            rs[v as usize] += i as i64;
            rc[v as usize] += 1i64;
        }
        
        arr.iter().enumerate().map(|(i, &v)| {
            let i = i as i64;
            let v = v as usize;
            rs[v] -= i;
            rc[v] -= 1;
            
            let ret = rs[v] - i * rc[v] + i * lc[v] - ls[v];
            
            ls[v] += i;
            lc[v] += 1;
            
            ret
        }).collect::<Vec<i64>>()
    }
}
