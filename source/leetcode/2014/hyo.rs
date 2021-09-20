use std::collections::HashMap;

// not sorted
fn get_permutations(n : usize) -> Vec<Vec<i32>> {
    if n == 0 {
        vec![]
    } else if n == 1 {
        vec![vec![0]]
    } else {
        let mut ret = Vec::new();
        for per in get_permutations(n-1) {
            for i in 0..n {
                let mut p = per.clone();
                p.insert(i, (n-1) as i32);
                ret.push(p);
            }
        }

        ret
    }
}

fn is_subsequence(s: &Vec<char>, t: &Vec<char>, k: i32) -> bool {
    let mut match_cnt = 0;
    let mut i = 0;
    for &c in s {
        if c == t[i] {
            match_cnt += 1;
            i = (i + 1) % t.len();
        }
    }
    
    t.len() * k as usize <= match_cnt
}

impl Solution {
    pub fn longest_subsequence_repeated_k(s: String, k: i32) -> String {
        let s = s.chars().collect::<Vec<_>>();
        let mut cnts = HashMap::new();
        for c in &s {
            *cnts.entry(c).or_insert(0) += 1;
        }
        
        let mut hot = Vec::new();
        for (c, cnt) in cnts {
            for i in 0..cnt/k {
                hot.push(*c);
            }
        }        
        
        let n = hot.len();
        let pers = get_permutations(n);
        let mut ret = Vec::new();
        for per in pers {
            let mut cs = Vec::new();
            for i in per {
                cs.push(hot[i as usize]);
                
                if ret.len() <= cs.len() && is_subsequence(&s, &cs, k) {
                    if ret.len() < cs.len() || ret < cs {
                        ret = cs.clone();
                    }
                } 
            }  
        }
        
        ret.iter().collect::<String>()
    }
}
