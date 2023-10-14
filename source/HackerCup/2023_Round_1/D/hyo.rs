use std::io::{Read, Write};

#[derive(Default, Debug, Clone, Copy)]
struct Node {
    max_idx: usize,
    max_val: i64,
    flipped_max_idx: usize,
    flipped_max_val: i64,
}

impl Node {
    pub fn new(max_idx: usize, max_val: i64, flipped_max_idx: usize, flipped_max_val: i64) -> Self {
        Node {
            max_idx,
            max_val,
            flipped_max_idx,
            flipped_max_val,
        }
    }

    pub fn flip(&mut self) {
        std::mem::swap(&mut self.max_idx, &mut self.flipped_max_idx);
        std::mem::swap(&mut self.max_val, &mut self.flipped_max_val);
    }

    pub fn pull(&mut self, left_child: Node, right_child: Node) {
        if left_child.max_val >= right_child.max_val {
            self.max_idx = left_child.max_idx;
            self.max_val = left_child.max_val;
        } else {
            self.max_idx = right_child.max_idx;
            self.max_val = right_child.max_val;
        }

        if left_child.flipped_max_val >= right_child.flipped_max_val {
            self.flipped_max_idx = left_child.flipped_max_idx;
            self.flipped_max_val = left_child.flipped_max_val;
        } else {
            self.flipped_max_idx = right_child.flipped_max_idx;
            self.flipped_max_val = right_child.flipped_max_val;
        }
    }
}

struct FlipLazySegTree {
    n: usize,
    nodes: Vec<Node>,
    lazy: Vec<bool>,
}

fn left_child_idx(i: usize) -> usize {
    i * 2 + 1
}

fn right_child_idx(i: usize) -> usize {
    i * 2 + 2
}

fn parent_idx(i: usize) -> usize {
    (i - 1) / 2
}

fn leaf_count(size: usize) -> usize {
    if size.count_ones() == 1 {
        size
    } else {
        1 << (64 - size.leading_zeros())
    }
}

impl FlipLazySegTree {
    pub fn new(n: usize) -> Self {
        let len = leaf_count(n) * 2 - 1;

        FlipLazySegTree {
            n,
            nodes: vec![Node::default(); len],
            lazy: vec![false; len],
        }
    }

    fn is_leaf(&self, i: usize) -> bool {
        left_child_idx(i) >= self.nodes.len()
    }

    fn pull(&mut self, i: usize) {
        if !self.is_leaf(i) {
            let left_child = self.nodes[left_child_idx(i)];
            let right_child = self.nodes[right_child_idx(i)];
            self.nodes[i].pull(left_child, right_child);
        }
    }

    fn push(&mut self, i: usize) {
        if self.lazy[i] {
            self.nodes[i].flip();
            self.lazy[i] = false;
            if !self.is_leaf(i) {
                self.lazy[left_child_idx(i)] ^= true;
                self.lazy[right_child_idx(i)] ^= true;
            }
        }
    }

    pub fn set(&mut self, idx: usize, val: i64, flipped_val: i64) {
        let mut left = 0;
        let mut right = leaf_count(self.n);
        let mut i = 0;
        while left + 1 < right {
            let mid = (left + right) / 2;
            if idx < mid {
                right = mid;
                i = left_child_idx(i);
            } else {
                left = mid;
                i = right_child_idx(i);
            }
        }

        self.nodes[i] = Node::new(left, val, left, flipped_val);
        while i > 0 {
            i = parent_idx(i);
            self.pull(i);
        }
    }

    fn flip_impl(&mut self, i: usize, l: usize, r: usize, left: usize, right: usize) {
        self.push(i);
        if r <= left || right <= l {
            return;
        }

        if left <= l && r <= right {
            self.lazy[i] ^= true;
            self.push(i);
            return;
        }

        let mid = (l + r) / 2;
        self.flip_impl(left_child_idx(i), l, mid, left, right);
        self.flip_impl(right_child_idx(i), mid, r, left, right);
        self.pull(i);
    }

    pub fn flip(&mut self, left: usize, right: usize) {
        self.flip_impl(0, 0, leaf_count(self.n), left, right);
    }

    pub fn max_idx(&self) -> usize {
        self.nodes[0].max_idx
    }
}

const MOD: i64 = 1_000_000_007;

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let vals = (0..n)
            .map(|_| input.next().unwrap().parse::<i64>().unwrap())
            .collect::<Vec<_>>();

        let mut seg_tree = FlipLazySegTree::new(n);
        for (i, &val) in vals.iter().enumerate() {
            seg_tree.set(i, val, val * (MOD - 1) % MOD);
        }

        let q = input.next().unwrap().parse::<usize>().unwrap();
        let ans: i64 = (0..q)
            .map(|_| {
                let left = input.next().unwrap().parse::<usize>().unwrap() - 1;
                let right = input.next().unwrap().parse::<usize>().unwrap();

                seg_tree.flip(left, right);

                seg_tree.max_idx() as i64 + 1
            })
            .sum();

        writeln!(stdout, "Case #{tc}: {}", ans).ok();
    }
}
