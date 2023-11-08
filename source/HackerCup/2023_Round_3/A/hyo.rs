use std::{
    collections::{HashMap, HashSet},
    io::{Read, Write},
};

struct DisjointSet {
    g: Vec<i32>,
    g_set: std::collections::HashSet<i32>,
    cnts: Vec<usize>,
}

impl DisjointSet {
    pub fn new(n: usize) -> Self {
        DisjointSet {
            g: (0..n as i32).collect::<Vec<_>>(),
            g_set: (0..n as i32).collect::<std::collections::HashSet<_>>(),
            cnts: vec![1; n],
        }
    }

    pub fn group(&mut self, mut x: i32) -> i32 {
        while self.g[x as usize] != x {
            let nx = self.g[x as usize];
            self.g[x as usize] = self.g[nx as usize];
            x = nx;
        }

        x
    }

    pub fn merge(&mut self, x: i32, y: i32) -> bool {
        let gx = self.group(x);
        let gy = self.group(y);

        if gx == gy {
            false
        } else {
            self.g[gy as usize] = gx;
            self.g_set.remove(&gy);
            self.cnts[gx as usize] += self.cnts[gy as usize];
            true
        }
    }

    pub fn get_group_set(&self) -> &std::collections::HashSet<i32> {
        &self.g_set
    }

    pub fn cnt(&mut self, x: i32) -> usize {
        let g = self.group(x);
        self.cnts[g as usize]
    }
}

struct Problem {
    n: usize,
    edges: Vec<(usize, usize)>,
}

impl Problem {
    fn new(n: usize, edges: Vec<(usize, usize)>) -> Self {
        Self { n, edges }
    }

    fn solve(&mut self) -> String {
        let partitions = self.get_partitions();
        let res = (1..=self.n)
            .filter(|i| self.n % i == 0)
            .filter(|i| self.check(&partitions, self.n / *i))
            .collect::<Vec<_>>();
        self.answer(res)
    }

    fn get_partitions(&self) -> HashMap<usize, usize> {
        let mut ds = DisjointSet::new(self.n);
        self.edges.iter().for_each(|&(u, v)| {
            ds.merge(u as i32, v as i32);
        });

        let mut ret = HashMap::new();
        ds.get_group_set()
            .clone()
            .iter()
            .map(|&i| ds.cnt(i))
            .for_each(|cnt| {
                *ret.entry(cnt).or_insert(0) += 1;
            });

        ret
    }

    fn check(&self, partitions: &HashMap<usize, usize>, p: usize) -> bool {
        // (len, count)
        let partitions = partitions.iter().collect::<Vec<_>>();
        let mut visited = HashSet::new();
        let mut stack = vec![vec![0; partitions.len()]];
        while !stack.is_empty() {
            let cur = stack.pop().unwrap();
            if visited.contains(&cur) {
                continue;
            }
            visited.insert(cur.clone());
            let cur_len_sum = cur
                .iter()
                .zip(partitions.iter())
                .map(|(&cnt, (&len, _))| cnt * len)
                .sum::<usize>();
            if cur_len_sum == self.n {
                return true;
            }

            let cur_part_len = cur_len_sum % p;

            for i in 0..partitions.len() {
                if cur[i] == *partitions[i].1 || cur_part_len + partitions[i].0 > p {
                    continue;
                }
                let mut nxt = cur.clone();
                nxt[i] += 1;
                stack.push(nxt);
            }
        }

        false
    }

    fn answer(&self, ans: Vec<usize>) -> String {
        ans.iter()
            .map(|i| i.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();
        let edges = (0..m)
            .map(|_| {
                let u = input.next().unwrap().parse::<usize>().unwrap();
                let v = input.next().unwrap().parse::<usize>().unwrap();
                (u - 1, v - 1)
            })
            .collect::<Vec<_>>();
        let mut prob = Problem::new(n, edges);
        let ans = prob.solve();

        writeln!(stdout, "Case #{tc}: {}", ans).ok();
    }
}
