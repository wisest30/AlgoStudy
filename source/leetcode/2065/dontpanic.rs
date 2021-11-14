#![allow(unused)]

use std::{
    cmp,
    collections::{HashMap, HashSet},
};

// A rough Rust translation of this python solution:
//   https://leetcode.com/problems/maximum-path-quality-of-a-graph/discuss/1563898/Python-Concise-DFS

pub fn maximal_path_quality(values: Vec<i32>, edges: Vec<Vec<i32>>, max_time: i32) -> i32 {
    let mut g = HashMap::<i32, HashMap<i32, i32>>::new();

    for e in edges {
        if let Some(h) = g.get_mut(&e[0]) {
            h.insert(e[1], e[2]);
        } else {
            let mut h = HashMap::<i32, i32>::new();
            h.insert(e[1], e[2]);
            g.insert(e[0], h);
        }
        if let Some(h) = g.get_mut(&e[1]) {
            h.insert(e[0], e[2]);
        } else {
            let mut h = HashMap::<i32, i32>::new();
            h.insert(e[0], e[2]);
            g.insert(e[1], h);
        }
    }

    fn dfs(
        i: i32,
        seen: &HashSet<i32>,
        time: i32,
        v: &Vec<i32>,
        g: &HashMap<i32, HashMap<i32, i32>>,
    ) -> i32 {
        let mut res = if i == 0 {
            seen.iter().map(|&j| v[j as usize]).sum()
        } else {
            0
        };

        let d = HashMap::<i32, i32>::new();
        let h = g.get(&i).unwrap_or(&d);
        for j in h.keys() {
            let x = h.get(&j).unwrap_or(&0);
            if time >= *x {
                let mut seen2 = seen.clone();
                seen2.insert(*j);
                res = std::cmp::max(res, dfs(*j, &seen2, time - *x, v, g));
            }
        }

        res
    };

    //let seen = HashSet::<i32>::from([0]);
    let seen: HashSet<i32> = vec![0].into_iter().collect();
    dfs(0, &seen, max_time, &values, &g)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn maximal_path_quality_typical() {
        let v = vec![0, 32, 10, 43];
        let e = vec![vec![0, 1, 10], vec![1, 2, 15], vec![0, 3, 10]];
        let m = 49;
        assert_eq!(75, maximal_path_quality(v, e, m));

        let v = vec![5, 10, 15, 20];
        let e = vec![vec![0, 1, 10], vec![1, 2, 10], vec![0, 3, 10]];
        let m = 30;
        assert_eq!(25, maximal_path_quality(v, e, m));

        let v = vec![1, 2, 3, 4];
        let e = vec![
            vec![0, 1, 10],
            vec![1, 2, 11],
            vec![2, 3, 12],
            vec![1, 3, 13],
        ];
        let m = 50;
        assert_eq!(7, maximal_path_quality(v, e, m));

        let v = vec![0, 1, 2];
        let e = vec![vec![1, 2, 10]];
        let m = 10;
        assert_eq!(0, maximal_path_quality(v, e, m));
    }
}
