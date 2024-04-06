use std::io::{Read, Write};

// a : 감소, b : 증가, x[i] : i번째 segment 시작 폐구간
struct ConvexHullTrick {
    a: Vec<i64>,
    b: Vec<i64>,
    x: Vec<f64>,
}

impl ConvexHullTrick {
    fn new() -> Self {
        Self {
            a: Vec::new(),
            b: Vec::new(),
            x: Vec::new(),
        }
    }

    fn add_line(&mut self, a: i64, b: i64) {
        if self.x.is_empty() {
            self.x.push(0.0);
        } else {
            assert_ne!(a, *self.a.last().unwrap());
            let mut x = (b - self.b.last().unwrap()) as f64 / (self.a.last().unwrap() - a) as f64;
            while !self.x.is_empty() && x < *self.x.last().unwrap() {
                self.a.pop();
                self.b.pop();
                self.x.pop();
                if !self.x.is_empty() {
                    assert_ne!(a, *self.a.last().unwrap());
                    x = (b - self.b.last().unwrap()) as f64 / (self.a.last().unwrap() - a) as f64;
                }
            }
            self.x.push(x);
        }

        self.a.push(a);
        self.b.push(b);
    }

    fn find_y(&self, x: i64) -> i64 {
        assert!(!self.x.is_empty());

        let mut l = 0;
        let mut r = self.x.len();
        while l + 1 < r {
            let m = (l + r) / 2;
            if self.x[m] <= x as f64 {
                l = m;
            } else {
                r = m;
            }
        }

        let l = l as usize;
        self.a[l] * x + self.b[l]
    }
}

struct Problem {
    n: usize,
    wh: Vec<(i64, i64)>,
}

impl Problem {
    fn new(n: usize, wh: Vec<(i64, i64)>) -> Self {
        Problem { n, wh }
    }

    fn solve(&mut self) -> i64 {
        self.sort_by_w();
        self.stack_remove();
        self.solve_dp()
    }

    fn sort_by_w(&mut self) {
        self.wh.sort_unstable()
    }

    fn stack_remove(&mut self) {
        let mut temp: Vec<(i64, i64)> = Vec::new();
        for &(w, h) in &self.wh {
            while !temp.is_empty() && temp.last().unwrap().1 <= h {
                temp.pop();
            }
            temp.push((w, h));
        }
        self.n = temp.len();
        self.wh = temp;
    }

    fn solve_dp(&self) -> i64 {
        if self.wh.len() == 1 {
            return self.wh[0].0 * self.wh[0].1;
        }

        let mut cht = ConvexHullTrick::new();
        cht.add_line(self.wh[1].1, self.wh[0].0 * self.wh[0].1);
        for j in 2..self.wh.len() {
            let dp = (self.wh[j - 1].0 * self.wh[0].1).min(cht.find_y(self.wh[j - 1].0));
            cht.add_line(self.wh[j].1, dp);
        }

        let w = self.wh.last().unwrap().0;
        (w * self.wh[0].1).min(cht.find_y(w))
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let wh = (0..n)
        .map(|_| {
            (
                input.next().unwrap().parse::<i64>().unwrap(),
                input.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect::<Vec<_>>();
    let ans = Problem::new(n, wh).solve();

    writeln!(stdout, "{}", ans).ok();
}
