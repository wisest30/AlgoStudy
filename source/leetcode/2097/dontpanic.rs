//#![allow(unused)]

//struct Solution {}

// https://leetcode.com/problems/valid-arrangement-of-pairs/discuss/1611983/Python-O(pairs.length)-Hierholzer's-Algorithm

use std::{
    collections::{HashMap, VecDeque},
    ops::{AddAssign, SubAssign},
};

impl Solution {
    pub fn valid_arrangement(pairs: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut g: HashMap<i32, VecDeque<i32>> = HashMap::with_capacity(pairs.len());
        let mut d: HashMap<i32, i32> = HashMap::with_capacity(pairs.len());
        pairs.iter().for_each(|p| {
            g.entry(p[0]).or_default().push_back(p[1]);
            d.entry(p[0]).or_default().add_assign(1);
            d.entry(p[1]).or_default().sub_assign(1);
        });

        let x = match d.iter().find(|(_, &v)| v > 0) {
            Some(i) => i.0.clone(),
            None => pairs[0][0],
        };


        fn dfs(g: &mut HashMap<i32, VecDeque<i32>>, cur: i32, route: &mut Vec<i32>) {
            while let Some(vdq) = g.get_mut(&cur) {
                if vdq.is_empty() {
                   break; 
                }
                else {
                if let Some(next) = vdq.pop_back() {
                    dfs(g, next, route);
                }
                }
            }
            route.push(cur);
        }

        let mut route = Vec::with_capacity(pairs.len());

        dfs(&mut g, x, &mut route);

        dbg!(&route);
        let it0 = route.iter().rev();
        let it1 = it0.clone().skip(1);
        let itzip = it0.zip(it1);

        itzip.map(|(&p0, &p1)| vec![p0, p1]).collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn valid_arrangement_typical() {
        let pairs = vec![vec![5, 1], vec![4, 5], vec![11, 9], vec![9, 4]];
        let expected = vec![vec![11, 9], vec![9, 4], vec![4, 5], vec![5, 1]];
        assert_eq!(expected, Solution::valid_arrangement(pairs));

        let pairs = vec![vec![1, 3], vec![3, 2], vec![2, 1]];
        let expected = vec![vec![1, 3], vec![3, 2], vec![2, 1]];
        assert_eq!(expected, Solution::valid_arrangement(pairs));

        let pairs = vec![vec![1, 2], vec![1, 3], vec![2, 1]];
        let expected = vec![vec![1, 2], vec![2, 1], vec![1, 3]];
        assert_eq!(expected, Solution::valid_arrangement(pairs));
    }
}
