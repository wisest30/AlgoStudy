use std::io::{Read, Write};

type T = i64;
struct MaxLeftRightSegTree {
    n: usize,
    max_left_sum: Vec<T>,
    max_right_sum: Vec<T>,
    max_sum: Vec<T>,
    sum: Vec<T>,
}

impl MaxLeftRightSegTree {
    pub fn new(n: usize) -> Self {
        MaxLeftRightSegTree {
            n,
            max_left_sum: vec![T::MIN; 4 * n + 10],
            max_right_sum: vec![T::MIN; 4 * n + 10],
            max_sum: vec![T::MIN; 4 * n + 10],
            sum: vec![T::MIN; 4 * n + 10],
        }
    }

    fn set_(&mut self, i: usize, l: usize, r: usize, pos: usize, x: T) {
        if l + 1 == r {
            self.max_left_sum[i] = self.max_left_sum[i].max(x);
            self.max_right_sum[i] = self.max_right_sum[i].max(x);
            self.max_sum[i] = x;
            self.sum[i] = x;
        } else {
            let m = (l + r) / 2;
            if pos < m {
                self.set_(i * 2 + 1, l, m, pos, x);
            } else {
                self.set_(i * 2 + 2, m, r, pos, x);
            }
            self.max_left_sum[i] = self.max_left_sum[i * 2 + 1]
                .max(self.sum[i * 2 + 1] + self.max_left_sum[i * 2 + 2]);
            self.max_right_sum[i] = self.max_right_sum[i * 2 + 2]
                .max(self.sum[i * 2 + 2] + self.max_right_sum[i * 2 + 1]);
            self.max_sum[i] = self.max_sum[i * 2 + 1]
                .max(self.max_sum[i * 2 + 2])
                .max(self.max_right_sum[i * 2 + 1] + self.max_left_sum[i * 2 + 2]);
            self.sum[i] = self.sum[i * 2 + 1] + self.sum[i * 2 + 2];
        }
    }

    pub fn set(&mut self, pos: usize, x: T) {
        self.set_(0, 0, self.n, pos, x);
    }

    fn max_left_sum_(&self, i: usize, l: usize, r: usize, left: usize, right: usize) -> T {
        let m = (l + r) / 2;
        if left >= right {
            0
        } else if l == left && r == right {
            self.max_left_sum[i]
        } else if right <= m {
            self.max_left_sum_(i * 2 + 1, l, m, left, right)
        } else if left >= m {
            self.max_left_sum_(i * 2 + 2, m, r, left, right)
        } else {
            self.max_left_sum_(i * 2 + 1, l, m, left, m).max(
                self.sum_(i * 2 + 1, l, m, left, m) + self.max_left_sum_(i * 2 + 2, m, r, m, right),
            )
        }
    }

    pub fn max_left_sum(&self, left: usize, right: usize) -> T {
        self.max_left_sum_(0, 0, self.n, left, right)
    }

    fn max_right_sum_(&self, i: usize, l: usize, r: usize, left: usize, right: usize) -> T {
        let m = (l + r) / 2;
        if left >= right {
            0
        } else if l == left && r == right {
            self.max_right_sum[i]
        } else if right <= m {
            self.max_right_sum_(i * 2 + 1, l, m, left, right)
        } else if left >= m {
            self.max_right_sum_(i * 2 + 2, m, r, left, right)
        } else {
            self.max_right_sum_(i * 2 + 2, m, r, m, right).max(
                self.sum_(i * 2 + 2, m, r, m, right)
                    + self.max_right_sum_(i * 2 + 1, l, m, left, m),
            )
        }
    }

    pub fn max_right_sum(&self, left: usize, right: usize) -> T {
        self.max_right_sum_(0, 0, self.n, left, right)
    }

    fn max_sum_(&self, i: usize, l: usize, r: usize, left: usize, right: usize) -> T {
        let m = (l + r) / 2;
        if left >= right {
            0
        } else if l == left && r == right {
            self.max_sum[i]
        } else if right <= m {
            self.max_sum_(i * 2 + 1, l, m, left, right)
        } else if left >= m {
            self.max_sum_(i * 2 + 2, m, r, left, right)
        } else {
            self.max_sum_(i * 2 + 1, l, m, left, m)
                .max(self.max_sum_(i * 2 + 2, m, r, m, right))
                .max(
                    self.max_right_sum_(i * 2 + 1, l, m, left, m)
                        + self.max_left_sum_(i * 2 + 2, m, r, m, right),
                )
        }
    }

    pub fn max_sum(&self, left: usize, right: usize) -> T {
        self.max_sum_(0, 0, self.n, left, right)
    }

    fn sum_(&self, i: usize, l: usize, r: usize, left: usize, right: usize) -> T {
        let m = (l + r) / 2;
        if left >= right {
            0
        } else if l == left && r == right {
            self.sum[i]
        } else if right <= m {
            self.sum_(i * 2 + 1, l, m, left, right)
        } else if left >= m {
            self.sum_(i * 2 + 2, m, r, left, right)
        } else {
            self.sum_(i * 2 + 1, l, m, left, m) + self.sum_(i * 2 + 2, m, r, m, right)
        }
    }

    pub fn sum(&self, left: usize, right: usize) -> T {
        self.sum_(0, 0, self.n, left, right)
    }
}

struct Problem {
    n: usize,
    vals: Vec<i64>,
    q: usize,
    query: Vec<(usize, usize, usize, usize)>,
    max_lr_seg_tree: MaxLeftRightSegTree,
}

impl Problem {
    fn new(n: usize, vals: Vec<i64>, q: usize, query: Vec<(usize, usize, usize, usize)>) -> Self {
        let mut max_lr_seg_tree = MaxLeftRightSegTree::new(n);
        for i in 0..n {
            max_lr_seg_tree.set(i, vals[i]);
        }

        Self {
            n,
            vals,
            q,
            query,
            max_lr_seg_tree,
        }
    }

    fn solve(&mut self) -> String {
        let mut ret = String::new();

        for &(l0, r0, l1, r1) in &self.query {
            let ans = if r0 <= l1 {
                self.max_lr_seg_tree.max_right_sum(l0, r0)
                    + self.max_lr_seg_tree.max_left_sum(l1, r1)
                    + self.max_lr_seg_tree.sum(r0, l1)
            } else {
                let l_max = self.max_lr_seg_tree.max_right_sum(l0, l1).max(0);
                let r_max = self.max_lr_seg_tree.max_left_sum(r0, r1).max(0);

                self.max_lr_seg_tree
                    .max_sum(l1, r0)
                    .max(self.max_lr_seg_tree.sum(l1, r0) + l_max + r_max)
                    .max(self.max_lr_seg_tree.max_left_sum(l1, r0) + l_max)
                    .max(self.max_lr_seg_tree.max_right_sum(l1, r0) + r_max)
            };

            ret.push_str(ans.to_string().as_str());
            ret.push('\n');
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
    let vals = (0..n)
        .map(|_| input.next().unwrap().parse::<i64>().unwrap())
        .collect::<Vec<_>>();
    let q = input.next().unwrap().parse::<usize>().unwrap();
    let queries = (0..q)
        .map(|_| {
            (
                input.next().unwrap().parse::<usize>().unwrap() - 1,
                input.next().unwrap().parse::<usize>().unwrap(),
                input.next().unwrap().parse::<usize>().unwrap() - 1,
                input.next().unwrap().parse::<usize>().unwrap(),
            )
        })
        .collect::<Vec<_>>();

    let ans = Problem::new(n, vals, q, queries).solve();

    writeln!(stdout, "{}", ans).ok();
}
