use std::cmp::max;
impl Solution {
    pub fn minimum_time(n: i32, relations: Vec<Vec<i32>>, time: Vec<i32>) -> i32 {
        let n = n as usize;
        let mut indegree = vec![0; n];
        let mut g = vec![Vec::new(); n];
                    
        relations.iter().for_each(|r| {
            let u = (r[0] - 1) as usize;
            let v = (r[1] - 1) as usize;
            indegree[v] += 1;
            g[u].push(v);
        });

        let mut order = (0..n).filter(|&x| indegree[x] == 0).collect::<Vec<usize>>();
        let mut i = 0;
        while i < order.len() {
            g[order[i]].iter().for_each(|&j| {
                indegree[j] -= 1;
                if indegree[j] == 0 {
                    order.push(j);
                }
            });
            i += 1;
        }

        let mut dp = time.clone();        
        order.iter().for_each(
            |&x| {
                g[x].iter().for_each(|&y| dp[y] = max(dp[y], dp[x] + time[y]));
            }
        );
        
        *dp.iter().max().unwrap()
    }
}
