use std::io::{Read, Write};

#[derive(Clone)]
struct Edge {
    to: usize,
    cap: i64,
    cost: i64,
    back_edge: (usize, usize), // (node idx, edge idx)
}

impl Edge {
    fn new(to: usize, cap: i64, cost: i64) -> Self {
        Self {
            to,
            cap,
            cost,
            back_edge: (0, 0),
        }
    }

    fn set_back_edge(&mut self, node_idx: usize, edge_idx: usize) {
        self.back_edge = (node_idx, edge_idx);
    }
}

#[derive(Clone, Default)]
struct Node {
    edges: Vec<Edge>,
}

impl Node {
    fn edges_len(&self) -> usize {
        self.edges.len()
    }
}

struct Problem {
    n: usize,
    a: Vec<i64>,
    h: Vec<i64>,
    l: Vec<i64>,
    nodes: Vec<Node>,
    s: usize,
    t: usize,
}

impl Problem {
    fn new(n: usize, a: Vec<i64>, h: Vec<i64>, l: Vec<i64>) -> Self {
        Problem {
            n,
            a,
            h,
            l,
            nodes: Vec::new(),
            s: 2 * n,
            t: 2 * n + 1,
        }
    }

    fn solve(&mut self) -> i64 {
        self.make_graph();
        -self.solve_mcmf()
    }

    fn make_graph(&mut self) {
        let max_a = *self.a.iter().max().unwrap();
        self.nodes.resize(2 * self.n + 2, Node::default());
        for u in 0..self.n {
            self.make_edge(
                self.s,
                u,
                if self.a[u] == max_a {
                    self.l[u]
                } else {
                    self.l[u] - 1
                },
                self.h[u],
            );
        }
        for u in 0..self.n {
            for v in 0..self.n {
                if self.a[u] > self.a[v] {
                    self.make_edge(u, v + self.n, 1, -(self.a[u] ^ self.a[v]));
                }
            }
        }
        for u in 0..self.n {
            self.make_edge(u + self.n, self.t, 1, self.h[u]);
        }
    }

    fn make_edge(&mut self, from: usize, to: usize, cap: i64, cost: i64) {
        self.nodes[from].edges.push(Edge::new(to, cap, cost));
        self.nodes[to].edges.push(Edge::new(from, 0, -cost));
        let edge_idx = self.nodes[to].edges_len() - 1;
        self.nodes[from]
            .edges
            .last_mut()
            .unwrap()
            .set_back_edge(to, edge_idx);
        let edge_idx = self.nodes[from].edges_len() - 1;
        self.nodes[to]
            .edges
            .last_mut()
            .unwrap()
            .set_back_edge(from, edge_idx);
    }

    fn solve_mcmf(&mut self) -> i64 {
        let mut total_cost = 0i64;
        loop {
            let (path, cost) = self.spfa();
            if path.is_empty() {
                break;
            }

            total_cost += cost;
            for (node_idx, edge_idx) in path {
                self.nodes[node_idx].edges[edge_idx].cap -= 1;
                let back_edge = self.nodes[node_idx].edges[edge_idx].back_edge;
                self.nodes[back_edge.0].edges[back_edge.1].cap += 1;
            }
        }
        total_cost
    }

    // shortest path fast algorithm
    fn spfa(&mut self) -> (Vec<(usize, usize)>, i64) {
        const INVALID_IDX: usize = usize::MAX;

        let mut que = std::collections::VecDeque::new();
        que.push_back(self.s);
        let mut in_que = vec![false; self.nodes.len()];
        in_que[self.s] = true;
        let mut dist = vec![i64::MAX; self.nodes.len()];
        dist[self.s] = 0;
        let mut prev = vec![(INVALID_IDX, INVALID_IDX); self.nodes.len()];

        while !que.is_empty() {
            let u = que.pop_front().unwrap();
            in_que[u] = false;

            for (edge_idx, edge) in self.nodes[u].edges.iter().enumerate() {
                if edge.cap == 0 {
                    continue;
                }

                let v = edge.to;
                if dist[u] + edge.cost < dist[v] {
                    dist[v] = dist[u] + edge.cost;
                    prev[v] = (u, edge_idx);
                    if !in_que[v] {
                        que.push_back(v);
                        in_que[v] = true;
                    }
                }
            }
        }

        if dist[self.t] == i64::MAX {
            return (Vec::new(), i64::MAX);
        }

        let mut path = vec![prev[self.t]];
        while path.last().unwrap().0 != self.s {
            path.push(prev[path.last().unwrap().0]);
        }

        (path, dist[self.t])
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let a = (0..n)
        .map(|_| input.next().unwrap().parse::<i64>().unwrap())
        .collect::<_>();
    let h = (0..n)
        .map(|_| input.next().unwrap().parse::<i64>().unwrap())
        .collect::<_>();
    let l = (0..n)
        .map(|_| input.next().unwrap().parse::<i64>().unwrap())
        .collect::<_>();

    let ans = Problem::new(n, a, h, l).solve();

    writeln!(stdout, "{}", ans).ok();
}
