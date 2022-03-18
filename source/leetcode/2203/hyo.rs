impl Solution {
    pub fn minimum_weight(n: i32, edges: Vec<Vec<i32>>, src1: i32, src2: i32, dest: i32) -> i64 {
        let n = n as usize;
        let src1 = src1 as usize;
        let src2 = src2 as usize;
        let dest = dest as usize;
        
        fn dijkstra(n: usize, g: &Vec<Vec<(usize, i64)>>, src: usize) -> Vec<i64> {
            let mut ret = vec![i64::MAX; n];
            let mut q = std::collections::BinaryHeap::new();
            q.push((0i64, src));
            while(!q.is_empty()) {
                let d = -q.peek().unwrap().0;
                let cur = q.pop().unwrap().1;
                
                if ret[cur] != i64::MAX {
                    continue;
                }
                
                ret[cur] = d;
                
                for &edge in &g[cur] {
                    q.push((-(d + edge.1), edge.0));
                }
            }
            
            ret
        }
        
        let mut g = vec![Vec::new(); n];
        let mut bg = vec![Vec::new(); n];
        for e in edges {
            g[e[0] as usize].push((e[1] as usize, e[2] as i64));
            bg[e[1] as usize].push((e[0] as usize, e[2] as i64));
        }
        
        let d1 = dijkstra(n, &g, src1);
        let d2 = dijkstra(n, &g, src2);
        let d3 = dijkstra(n, &bg, dest);
        
        let mut ret = i64::MAX;
        for i in 0..n {
            if d1[i] == i64::MAX || d2[i] == i64::MAX || d3[i] == i64::MAX {
                continue;
            }
            
            ret = std::cmp::min(ret, d1[i] + d2[i] + d3[i]);
        }
        
        if ret == i64::MAX {
            -1
        } else {
            ret
        }
    }
}
