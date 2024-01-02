use std::io::{Read, Write};

#[derive(Debug)]
struct HalfLine {
    a: i64,
    b: i64,
    s: f64,
    i: usize,
}

impl HalfLine {
    fn new(a: i64, b: i64, s: f64, i: usize) -> Self {
        Self { a, b, s, i }
    }

    fn intersect(&self, other: &Self) -> f64 {
        (other.b - self.b) as f64 / (self.a - other.a) as f64
    }
}

struct Problem {
    n: usize,
    a: i64,
    b: i64,
    c: i64,
    val: Vec<i64>,
    prefix_sum: Vec<i64>,
}

impl Problem {
    fn new(n: usize, a: i64, b: i64, c: i64, val: Vec<i64>) -> Self {
        Self {
            n,
            a,
            b,
            c,
            val,
            prefix_sum: vec![0; n + 1],
        }
    }

    fn solve(&mut self) -> i64 {
        self.generate_prefix_sum();

        let mut dp = vec![0; self.n + 1];
        let mut st = vec![HalfLine::new(0, 0, 0.0, 0)];
        for i in 1..=self.n {
            let j = self.find_max_prev_index(&st, i);

            dp[i] = dp[j] + self.f(self.prefix_sum[i] - self.prefix_sum[j]);

            let pi = self.prefix_sum[i];
            let mut new_line = HalfLine::new(-2 * self.a * pi, dp[i] + self.a * pi * pi, 0.0, i);
            while !st.is_empty() && st.last().unwrap().intersect(&new_line) < st.last().unwrap().s {
                st.pop();
            }
            new_line.s = st.last().unwrap().intersect(&new_line);
            st.push(new_line);
        }

        dp[self.n] + self.b * self.prefix_sum[self.n]
    }

    fn generate_prefix_sum(&mut self) {
        for i in 0..self.n {
            self.prefix_sum[i + 1] = self.prefix_sum[i] + self.val[i];
        }
    }

    fn find_max_prev_index(&self, st: &Vec<HalfLine>, i: usize) -> usize {
        let mut left = 0usize;
        let mut right = st.len();
        let p = self.prefix_sum[i] as f64;
        while left + 1 < right {
            let m = (left + right) / 2;
            if st[m].s <= p {
                left = m;
            } else {
                right = m;
            }
        }

        st[left].i
    }

    fn f(&self, x: i64) -> i64 {
        self.a * x * x + self.c
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let a = input.next().unwrap().parse::<i64>().unwrap();
    let b = input.next().unwrap().parse::<i64>().unwrap();
    let c = input.next().unwrap().parse::<i64>().unwrap();
    let val = (0..n)
        .map(|_| input.next().unwrap().parse::<i64>().unwrap())
        .collect::<Vec<i64>>();

    let ans = Problem::new(n, a, b, c, val).solve();

    writeln!(stdout, "{}", ans).ok();
}
