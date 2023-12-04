use std::io::{Read, Write};

struct Problem {
    n: usize,
    v: Vec<i32>,
}

impl Problem {
    fn new(n: usize, v: Vec<i32>) -> Self {
        Self { n, v }
    }

    fn solve(&mut self) -> i32 {
        let mut ans = 0;
        for i in 0..self.n - 2 {
            ans += self.consume(i, 2, self.v[i].min(self.v[i + 1] - self.v[i + 2]).max(0));
            ans += self.consume(i, 3, self.v[i].min(self.v[i + 1]).min(self.v[i + 2]));
            ans += self.consume(i, 1, self.v[i]);
        }

        ans += self.consume(self.n - 2, 2, self.v[self.n - 2].min(self.v[self.n - 1]));
        ans += self.consume(self.n - 2, 1, self.v[self.n - 2]);
        ans += self.consume(self.n - 1, 1, self.v[self.n - 1]);

        ans
    }

    fn consume(&mut self, i: usize, k: usize, cnt: i32) -> i32 {
        (0..k).for_each(|j| self.v[i + j] -= cnt);
        match k {
            1 => cnt * 3,
            2 => cnt * 5,
            3 => cnt * 7,
            _ => panic!("invalid k"),
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
    let v: Vec<i32> = (0..n)
        .map(|_| input.next().unwrap().parse::<i32>().unwrap())
        .collect();
    let ans = Problem::new(n, v).solve();

    writeln!(stdout, "{}", ans).ok();
}
