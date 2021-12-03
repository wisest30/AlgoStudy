impl Solution {
    pub fn find_all_people(n: i32, meetings: Vec<Vec<i32>>, first_person: i32) -> Vec<i32> {
        use std::collections::{HashMap, HashSet};
        
        let n = n as usize;
        
        let mut edges_at_time = vec![Vec::new(); 100001];
        meetings.iter().for_each(|x| {
            edges_at_time[x[2] as usize].push((x[0], x[1]));
        });
        
        let mut know = vec![false; n];
        know[0] = true;
        know[first_person as usize] = true;
        
        for time in (0..=100000) {
            let mut g: HashMap<usize, Vec::<usize>> = HashMap::new();
            let mut visited: HashSet<usize> = HashSet::new();
            let mut stack: Vec<usize> = Vec::new();
            
            edges_at_time[time].iter().for_each(|&x| {
                g.entry(x.0 as usize).or_insert(Vec::new()).push(x.1 as usize);
                g.entry(x.1 as usize).or_insert(Vec::new()).push(x.0 as usize);
                
                if know[x.0 as usize] {
                    stack.push(x.0 as usize);
                }
                if know[x.1 as usize] {
                    stack.push(x.1 as usize);
                }
            });
            
            while !stack.is_empty() {
                let cur = stack.pop().unwrap();
                if visited.contains(&cur) {
                    continue;
                } else {
                    visited.insert(cur);
                }
                
                know[cur] = true;
                
                for &nxt in g.get(&cur).unwrap() {
                    stack.push(nxt);
                }
            }
        }
        
        (0..n).filter(|&x| know[x]).map(|x| x as i32).collect::<Vec<i32>>()
    }
}
