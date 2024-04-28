use std::io::{Read, Write};

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

fn gcd(mut x: T, mut y: T) -> T {
    while y > 0 {
        x = x % y;
        std::mem::swap(&mut x, &mut y);
    }
    x
}

struct GcdSegTree {
    n: usize,
    val: Vec<T>,
}

impl GcdSegTree {
    pub fn new(n: usize) -> Self {
        GcdSegTree {
            n,
            val: vec![1; 4 * n + 10],
        }
    }

    fn set_(&mut self, i: usize, l: usize, r: usize, pos: usize, x: T) {
        if l + 1 == r {
            self.val[i] = x;
        } else {
            let m = (l + r) / 2;
            if pos < m {
                self.set_(i * 2 + 1, l, m, pos, x);
            } else {
                self.set_(i * 2 + 2, m, r, pos, x);
            }
            self.val[i] = gcd(self.val[i * 2 + 1], self.val[i * 2 + 2]);
        }
    }

    pub fn set(&mut self, pos: usize, x: T) {
        self.set_(0, 0, self.n, pos, x);
    }

    fn get_(&self, i: usize, l: usize, r: usize, left: usize, right: usize) -> T {
        if left <= l && r <= right {
            self.val[i]
        } else {
            let m = (l + r) / 2;

            if right <= m {
                self.get_(i * 2 + 1, l, m, left, right)
            } else if m <= left {
                self.get_(i * 2 + 2, m, r, left, right)
            } else {
                gcd(
                    self.get_(i * 2 + 1, l, m, left, right),
                    self.get_(i * 2 + 2, m, r, left, right),
                )
            }
        }
    }

    pub fn get(&self, left: usize, right: usize) -> T {
        self.get_(0, 0, self.n, left, right)
    }
}

struct Problem {
    n: usize,
    v: Vec<i64>,
    q: usize,
    reqs: Vec<(i64, i64, i64)>,
    lazy_st: SumLazySegTree,
    gcd_st: GcdSegTree,
}

impl Problem {
    fn new(n: usize, v: Vec<i64>, q: usize, reqs: Vec<(i64, i64, i64)>) -> Self {
        let lazy_st = Self::construct_lazy_seg_tree(&v);
        let gcd_st = Self::construct_gcd_seg_tree(&v);
        Self {
            n,
            v,
            q,
            reqs,
            lazy_st,
            gcd_st,
        }
    }

    fn construct_lazy_seg_tree(v: &[i64]) -> SumLazySegTree {
        let mut st = SumLazySegTree::new(v.len());
        for i in 0..v.len() {
            st.upd(i, i + 1, v[i]);
        }
        st
    }

    fn construct_gcd_seg_tree(v: &[i64]) -> GcdSegTree {
        let mut st = GcdSegTree::new(v.len());
        for i in 0..v.len() - 1 {
            st.set(i, (v[i] - v[i + 1]).abs());
        }
        st.set(v.len() - 1, *v.last().unwrap());
        st
    }

    fn solve(&mut self) -> String {
        let mut ret = String::new();
        let reqs = std::mem::take(&mut self.reqs);
        for req in reqs {
            if req.0 == 0 {
                ret += &self.request(req.1, req.2);
                ret.push('\n');
            } else {
                self.add(req.0, req.1, req.2);
            }
        }

        ret
    }

    fn request(&mut self, l: i64, r: i64) -> String {
        let l = (l - 1) as usize;
        let r = r as usize;
        let ans = if l + 1 == r {
            self.lazy_st.get(l, r)
        } else {
            gcd(self.gcd_st.get(l, r - 1), self.lazy_st.get(r - 1, r))
        };

        ans.to_string()
    }

    fn add(&mut self, val: i64, l: i64, r: i64) {
        let l = (l - 1) as usize;
        let r = r as usize;

        self.lazy_st.upd(l, r, val);

        let a = self.lazy_st.get(r - 1, r);
        let b = if r == self.n {
            0
        } else {
            self.lazy_st.get(r, r + 1)
        };
        self.gcd_st.set(l, (a - b).abs());

        if l > 0 {
            let a = self.lazy_st.get(l - 1, l);
            let b = self.lazy_st.get(l, l + 1);
            self.gcd_st.set(l - 1, (a - b).abs());
        }
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let v = (0..n)
        .map(|_| input.next().unwrap().parse::<i64>().unwrap())
        .collect::<Vec<_>>();
    let q = input.next().unwrap().parse::<usize>().unwrap();
    let reqs = (0..q)
        .map(|_| {
            (
                input.next().unwrap().parse::<i64>().unwrap(),
                input.next().unwrap().parse::<i64>().unwrap(),
                input.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect::<Vec<_>>();
    let ans = Problem::new(n, v, q, reqs).solve();

    writeln!(stdout, "{}", ans).ok();
}
