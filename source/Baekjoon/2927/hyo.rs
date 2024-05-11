use std::io::{Read, Write};

struct DisjointSet {
    g: Vec<i32>,
}

impl DisjointSet {
    pub fn new(n: usize) -> Self {
        DisjointSet {
            g: (0..n as i32).collect::<Vec<_>>(),
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
            true
        }
    }
}

type T = i64;
struct SumLazySegTree {
    n: usize,
    val: Vec<T>,
    lazy: Vec<T>,
}

impl SumLazySegTree {
    fn new(n: usize) -> Self {
        SumLazySegTree {
            n,
            val: vec![0; 4 * n + 20],
            lazy: vec![0; 4 * n + 20],
        }
    }

    fn push(&mut self, i: usize, l: usize, r: usize) {
        self.val[i] += (r - l) as T * self.lazy[i];
        if l + 1 != r {
            self.lazy[i * 2 + 1] += self.lazy[i];
            self.lazy[i * 2 + 2] += self.lazy[i];
        }
        self.lazy[i] = 0;
    }

    fn pull(&mut self, i: usize) {
        self.val[i] = self.val[i * 2 + 1] + self.val[i * 2 + 2];
    }

    fn upd_impl(&mut self, i: usize, l: usize, r: usize, left: usize, right: usize, x: T) {
        self.push(i, l, r);
        if r <= left || right <= l {
            return;
        } else if left <= l && r <= right {
            self.lazy[i] = x;
            self.push(i, l, r);
            return;
        }
        let m = (l + r) / 2;
        self.upd_impl(i * 2 + 1, l, m, left, right, x);
        self.upd_impl(i * 2 + 2, m, r, left, right, x);
        self.pull(i);
    }

    fn get_impl(&mut self, i: usize, l: usize, r: usize, left: usize, right: usize) -> T {
        self.push(i, l, r);
        if left <= l && r <= right {
            return self.val[i];
        }
        let m = (l + r) / 2;
        let mut ret = 0;
        if left < m {
            ret += self.get_impl(i * 2 + 1, l, m, left, right);
        }
        if right > m {
            ret += self.get_impl(i * 2 + 2, m, r, left, right);
        }
        ret
    }

    pub fn upd(&mut self, left: usize, right: usize, x: T) {
        self.upd_impl(0, 0, self.n, left, right, x);
    }

    pub fn get(&mut self, left: usize, right: usize) -> T {
        self.get_impl(0, 0, self.n, left, right)
    }
}

enum Command {
    Bridge(usize, usize),
    Penguins(usize, usize),
    Excursion(usize, usize),
}

impl Command {
    fn new(s: &str, a: usize, b: usize) -> Self {
        match s {
            "bridge" => Self::Bridge(a, b),
            "penguins" => Self::Penguins(a, b),
            "excursion" => Self::Excursion(a, b),
            _ => panic!(),
        }
    }
}

struct HeavyLightDecomposition {
    n: usize,
    g: Vec<Vec<usize>>,
    size: Vec<usize>,
    depth: Vec<i32>,
    parent: Vec<i32>,
    top: Vec<usize>,
    in_time: Vec<usize>,
    seg_tree: SumLazySegTree,
}

impl HeavyLightDecomposition {
    pub fn new(n: usize, g: Vec<Vec<usize>>) -> Self {
        assert_eq!(n, g.len());
        Self {
            n,
            g,
            size: vec![1; n],
            depth: vec![0; n],
            parent: vec![-1; n],
            top: (0..n).collect::<Vec<_>>(),
            in_time: vec![0; n],
            seg_tree: SumLazySegTree::new(n),
        }
    }

    // multiple tree
    pub fn dfs(&mut self) {
        let mut visited = vec![false; self.n];
        let mut time = 0;
        for cur in 0..self.n {
            if !visited[cur] {
                self.dfs_root(cur, &mut visited, &mut time);
            }
        }
    }

    // one tree
    pub fn dfs_root(&mut self, root: usize, call_visited: &mut Vec<bool>, time: &mut usize) {
        let mut st = vec![root];
        let mut visited = vec![false; self.n];

        while !st.is_empty() {
            let &cur = st.last().unwrap();
            if visited[cur] {
                let mut max_size = 0;
                let mut max_idx = -1;
                for (i, &nxt) in self.g[cur].iter().enumerate() {
                    if nxt as i32 == self.parent[cur] {
                        continue;
                    }

                    self.size[cur] += self.size[nxt];
                    if self.size[nxt] > max_size {
                        max_size = self.size[nxt];
                        max_idx = i as i32;
                    }
                }
                if max_idx != -1 {
                    self.g[cur].swap(0, max_idx as usize);
                }

                st.pop();
            } else {
                visited[cur] = true;
                call_visited[cur] = true;
                for &nxt in &self.g[cur] {
                    if nxt as i32 == self.parent[cur] {
                        continue;
                    }

                    self.depth[nxt] = self.depth[cur] + 1;
                    self.parent[nxt] = cur as i32;
                    st.push(nxt);
                }
            }
        }

        let mut st = vec![root];
        while !st.is_empty() {
            let cur = st.pop().unwrap();
            self.in_time[cur] = *time;
            *time += 1;
            if !self.g[cur].is_empty() && self.g[cur][0] as i32 != self.parent[cur] {
                self.top[self.g[cur][0]] = self.top[cur];
            }
            for &nxt in self.g[cur].iter().rev() {
                if nxt as i32 == self.parent[cur] {
                    continue;
                }

                st.push(nxt);
            }
        }
    }

    pub fn seg_idx(&self, node_idx: usize) -> usize {
        self.in_time[node_idx]
    }

    pub fn upd(&mut self, mut u: usize, mut v: usize, x: T) {
        if u == v {
            self.seg_tree.upd(self.seg_idx(u), self.seg_idx(u) + 1, x);
            return;
        }

        while self.top[u] != self.top[v] {
            if self.depth[self.top[u]] < self.depth[self.top[v]] {
                std::mem::swap(&mut u, &mut v);
            }
            let t = self.top[u];
            self.seg_tree.upd(self.seg_idx(t), self.seg_idx(u) + 1, x);
            assert_ne!(self.parent[t], -1);
            u = self.parent[t] as usize;
        }

        if self.depth[u] < self.depth[v] {
            std::mem::swap(&mut u, &mut v);
        }
        self.seg_tree.upd(self.seg_idx(v), self.seg_idx(u) + 1, x);
    }

    pub fn get(&mut self, mut u: usize, mut v: usize) -> T {
        if u == v {
            return self.seg_tree.get(self.seg_idx(u), self.seg_idx(u) + 1);
        }

        let mut ret = 0;
        while self.top[u] != self.top[v] {
            if self.depth[self.top[u]] < self.depth[self.top[v]] {
                std::mem::swap(&mut u, &mut v);
            }
            let t = self.top[u];
            ret += self.seg_tree.get(self.seg_idx(t), self.seg_idx(u) + 1);
            assert_ne!(self.parent[t], -1);
            u = self.parent[t] as usize;
        }

        if self.depth[u] < self.depth[v] {
            std::mem::swap(&mut u, &mut v);
        }
        ret += self.seg_tree.get(self.seg_idx(v), self.seg_idx(u) + 1);
        ret
    }
}

struct Problem {
    n: usize,
    counts: Vec<usize>,
    q: usize,
    commands: Vec<Command>,
}

impl Problem {
    fn new(n: usize, counts: Vec<usize>, q: usize, commands: Vec<Command>) -> Self {
        Self {
            n,
            counts,
            q,
            commands,
        }
    }
    fn solve(&mut self) -> String {
        let mut ds = DisjointSet::new(self.n);
        let mut g = vec![Vec::new(); self.n];
        for cmd in &self.commands {
            if let &Command::Bridge(u, v) = cmd {
                if ds.merge(u as i32 - 1, v as i32 - 1) {
                    g[u - 1].push(v - 1);
                    g[v - 1].push(u - 1);
                }
            }
        }

        let mut hld = HeavyLightDecomposition::new(self.n, g.clone());
        hld.dfs();

        for (i, &count) in self.counts.iter().enumerate() {
            hld.upd(i, i, count as i64);
        }

        let mut ds = DisjointSet::new(self.n);
        let mut ret = String::new();
        for cmd in &self.commands {
            match cmd {
                &Command::Bridge(u, v) => {
                    let u = u - 1;
                    let v = v - 1;
                    if ds.merge(u as i32, v as i32) {
                        ret += "yes\n";
                    } else {
                        ret += "no\n";
                    }
                }
                &Command::Excursion(u, v) => {
                    let u = u - 1;
                    let v = v - 1;
                    if ds.group(u as i32) == ds.group(v as i32) {
                        ret += &hld.get(u, v).to_string();
                        ret.push('\n');
                    } else {
                        ret += "impossible\n";
                    }
                }
                &Command::Penguins(u, count) => {
                    let u = u - 1;
                    let old_value = hld.get(u, u);
                    hld.upd(u, u, count as i64 - old_value);
                }
            }
        }

        ret
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let counts = (0..n)
        .map(|_| input.next().unwrap().parse::<usize>().unwrap())
        .collect::<Vec<_>>();
    let q = input.next().unwrap().parse::<usize>().unwrap();
    let commands = (0..q)
        .map(|_| {
            let s = input.next().unwrap();
            let a = input.next().unwrap().parse::<usize>().unwrap();
            let b = input.next().unwrap().parse::<usize>().unwrap();
            Command::new(s, a, b)
        })
        .collect::<Vec<_>>();

    let ans = Problem::new(n, counts, q, commands).solve();

    writeln!(stdout, "{}", ans).ok();
}
