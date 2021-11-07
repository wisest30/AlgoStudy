use std::cmp::max;
impl Solution {
    pub fn maximal_path_quality(values: Vec<i32>, edges: Vec<Vec<i32>>, max_time: i32) -> i32 {
        let n = values.len();
        let mut g = vec![Vec::new(); n];
        for e in edges {
            g[e[0] as usize].push((e[1] as usize, e[2]));
            g[e[1] as usize].push((e[0] as usize, e[2]));
        }
        
        let get_score = |path: &Vec::<usize>| {
            let mut v = path.clone();
            v.sort();
            v.dedup();            
            v.iter().fold(0i32, |acc, &i| acc + values[i])
        };
        
        let mut ans = values[0];
        let mut st = vec![(0, Vec::<usize>::new())];
        while !st.is_empty() {
            let val = st.pop().unwrap();
            let time = val.0;
            let mut path = val.1;
            let cur = *path.last().unwrap_or(&0);

            if time > max_time {
                continue;
            }
            
            if cur == 0 {
                ans = max(ans, get_score(&path));
            }
            
            for &(nxt, t) in &g[cur] {
                path.push(nxt);
                st.push((time + t, path.clone()));
                path.pop();
            }
        }
        
        ans
    }
}
