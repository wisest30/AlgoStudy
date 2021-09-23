#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("parse fail");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("read fail");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
type FenwickTreeValueT = i64;
struct FenwickTree {
    n : usize,
    f : Vec<FenwickTreeValueT>
}

impl FenwickTree {
    pub fn new(sz: usize) -> Self {
        Self {
            n : sz+10,
            f : vec![0; sz+10],
        }
    }

    pub fn update(&mut self, idx: usize, val: FenwickTreeValueT) {
        let mut i = idx;
        while i < self.f.len() {
            self.f[i] += val;
            i |= i+1;
        }
    }

    // sum of [0, right)
    pub fn get_pre_sum(&self, right: usize) -> FenwickTreeValueT {
        if right == 0 {
            0
        } else {
            let mut ret = 0;
            let mut i = right - 1;
            loop {
                ret += self.f[i];
                if i & (i+1) == 0 {
                    break;
                }
                i = (i & (i+1)) - 1;
            }

            ret
        }
    }

    pub fn less_equal_k(&self, k: FenwickTreeValueT) -> usize {
        let mut i = 0;
        while (1 << (i + 1)) <= self.n {
            i += 1;
        }

        let mut sum = 0;
        let mut right = 0;
        loop {
            while right + (1 << i) - 1 >= self.n {
                i -= 1;
            }
            let nxt_sum = sum + self.f[right + (1 << i) - 1];
            if nxt_sum <= k {
                sum = nxt_sum;
                right |= 1 << i;
            }

            if i == 0 || right == self.n {
                break;
            } else {
                i -= 1;
            }
        }

        right
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let test_case = scan.next::<usize>();

    for tc in 1..=test_case {
        let _ = scan.next::<usize>();
        let n = scan.next::<usize>();
        let k = scan.next::<usize>();

        let mut v = Vec::with_capacity(n);
        for _ in 0..n {
            let h = scan.next::<i64>();
            let s = scan.next::<i64>();
            let e = scan.next::<i64>() + 1;
            v.push((h, s, e));
        }

        v.sort_by(|a, b| b.cmp(a));
        // (day, type, idx)
        let mut time_points = Vec::with_capacity(n * 2);
        for i in 0..n {
            time_points.push((v[i].1, 1, i));
            time_points.push((v[i].2, 0, i));
        }
        time_points.sort();

        let mut ft1 = FenwickTree::new(n);
        let mut ft2 = FenwickTree::new(n);
        let mut ans = 0;
        for (_, t, i) in time_points {
            if t == 0 {
                ft1.update(i, -v[i].0);
                ft2.update(i, -1);
            } else {
                ft1.update(i, v[i].0);
                ft2.update(i, 1);
                let right = ft2.less_equal_k(k as i64);
                ans = max(ans, ft1.get_pre_sum(right));
            }
        }

        writeln!(out, "Case #{}: {}", tc, ans).ok();
    }
}
