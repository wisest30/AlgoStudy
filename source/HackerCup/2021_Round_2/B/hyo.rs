#[allow(unused_imports)]
use std::{
    io::{BufWriter, stdin, stdout, Write},
    str::FromStr, cmp::{min,max,Ordering},
    collections::HashMap,
};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}

#[allow(dead_code)]
impl Scanner {
    fn next<T: FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("parse fail");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("read fail");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }

    pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
        (0..len).map(|_| self.next()).collect()
    }
}

///////////////////////////////////////////////////////////////////////////////
#[derive(Debug)]
struct DisjointSet {
    n: usize,
    g: Vec<usize>,
    cnts: Vec<usize>,
}

impl DisjointSet {
    pub fn new(sz: usize) -> Self {
        Self {
            n: sz,
            g: (0..sz).collect(),
            cnts: vec![1; sz],
        }
    }

    pub fn find(&mut self, x: usize) -> usize {
        if self.g[x] == x {
            x
        } else {
            self.g[x] = self.find(self.g[x]);
            self.g[x]
        }
    }

    pub fn merge(&mut self, x: usize, y: usize) -> bool {
        let gx = self.find(x);
        let gy = self.find(y);
        if gx == gy {
            false
        } else {
            self.g[gy] = gx;
            self.cnts[gx] += self.cnts[gy];
            true
        }
    }

    pub fn get_cnt(&mut self, x: usize) -> usize {
        let g = self.find(x);
        self.cnts[g]
    }
}

fn dfs(g: &Vec<Vec<usize>>, cur: usize, prev: usize, ds: &mut DisjointSet) -> (usize, usize) {
    let mut ans = 0;
    let mut node_cnt = 1;
    for &nxt in &g[cur] {
        if nxt != prev {
            let (sub_ans, sub_node_cnt) = dfs(g, nxt, cur, ds);
            ans += sub_ans;
            node_cnt += sub_node_cnt;
        }
    }

    if cur != 0 && node_cnt == ds.get_cnt(cur) {
        ans += 1;
        node_cnt = 0;
    } else if cur != 0 {
        ds.merge(cur, prev);
    }

    (ans, node_cnt)
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let test_case = scan.next::<usize>();
    for tc in 1..=test_case {
        let n = scan.next::<usize>();
        let mut g = vec![Vec::new(); n];
        for _ in 0..n-1 {
            let u = scan.next::<usize>() - 1;
            let v = scan.next::<usize>() - 1;
            g[u].push(v);
            g[v].push(u);
        }

        let mut f = scan.next_vec::<usize>(n);
        f.iter_mut().for_each(|x| *x -= 1);

        let mut ds = DisjointSet::new(n);

        let mut first_f = HashMap::new();
        for i in 0..n {
            ds.merge(*first_f.get(&f[i]).unwrap_or(&i), i);
            first_f.insert(f[i], i);
        }
        
        let ans = dfs(&g, 0, n, &mut ds).0;

        writeln!(out, "Case #{}: {}", tc, ans).expect("wrong write");
    }
}
