impl Solution {
    pub fn maximum_invitations(favorite: Vec<i32>) -> i32 {
        use std::cmp::max;
        let n = favorite.len();
        let mut g = vec![Vec::new(); n];
        let mut bg = vec![Vec::new(); n];
        favorite.iter().enumerate().for_each(|(i, &x)| { g[i].push(x as usize); bg[x as usize].push(i); });
        let mut max_cycle_len = 0;
        {
            let mut visited_time = vec![0usize; n];
            let mut in_path = vec![false; n];
            let mut time = 1usize;
            for i in 0..n {
                if visited_time[i] > 0 { continue; }
                let mut st = vec![i];
                while !st.is_empty() {
                    let cur = *st.last().unwrap();
                    if in_path[cur] {
                        in_path[cur] = false;
                        st.pop();
                        continue;
                    }
                    in_path[cur] = true;
                    visited_time[cur] = time;
                    time += 1;
                    for &nxt in &g[cur] {
                        if in_path[nxt] {
                            max_cycle_len = max(max_cycle_len, visited_time[cur] - visited_time[nxt] + 1);
                        } else if visited_time[nxt] == 0 {
                            st.push(nxt);
                        }
                    }
                }
            }
        }
        let mut max_non_cycle_len = 0;
        {
            let mut depth = vec![0; n];
            for i in 0..n {
                if favorite[favorite[i] as usize] as usize == i {
                    let mut st = vec![i];
                    let mut max_depth = 0;
                    while !st.is_empty() {
                        let cur = st.pop().unwrap();
                        for &nxt in &bg[cur] {
                            if nxt != favorite[i] as usize {
                                st.push(nxt);
                                depth[nxt] = depth[cur] + 1;
                                max_depth = max(max_depth, depth[nxt]);
                            }
                        }
                    }
                    max_non_cycle_len += max_depth + 1;
                }
            }
        }
        max(max_cycle_len, max_non_cycle_len) as i32
    }
}
