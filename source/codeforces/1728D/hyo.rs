use std::cmp::Ordering;
use std::io::{Read, Write};

#[derive(Clone, Debug)]
enum Res {
    None,
    Win,
    Draw,
    DrawWithChar(char),
    Lose,
}

struct DP {
    s: Vec<char>,
    cache: Vec<Vec<Res>>,
}

impl DP {
    pub fn new(s: &str) -> Self {
        let n = s.len();

        Self {
            s: s.chars().collect::<Vec<_>>(),
            cache: vec![vec![Res::None; n + 1]; n + 1],
        }
    }

    pub fn solve(&mut self, left: usize, right: usize) -> Res {
        if left == right {
            return Res::Draw;
        }

        let Res::None = self.cache[left][right] else {
            return self.cache[left][right].clone();
        };

        let sub_ret0 = self.solve(left + 1, right);
        let sub_ret1 = self.solve(left, right - 1);

        self.cache[left][right] = match (sub_ret0, sub_ret1) {
            (Res::Lose, _) | (_, Res::Lose) => Res::Win,
            (Res::Win, Res::Win) => Res::Lose,
            (Res::Win, Res::Draw) => Res::DrawWithChar(self.s[right - 1]),
            (Res::Win, Res::DrawWithChar(c)) => match self.s[right - 1].cmp(&c) {
                Ordering::Less => Res::Win,
                Ordering::Equal => Res::Draw,
                Ordering::Greater => Res::Lose,
            },
            (Res::Draw, Res::Win) => Res::DrawWithChar(self.s[left]),
            (Res::Draw, Res::Draw) => Res::DrawWithChar(self.s[left].min(self.s[right - 1])),
            (Res::DrawWithChar(c), Res::Win) => match self.s[left - 1].cmp(&c) {
                Ordering::Less => Res::Win,
                Ordering::Equal => Res::Draw,
                Ordering::Greater => Res::Lose,
            },
            (Res::DrawWithChar(c0), Res::DrawWithChar(c1)) => {
                if self.s[left] < c0 || self.s[right - 1] < c1 {
                    Res::Win
                } else if self.s[left] == c0 || self.s[right - 1] == c1 {
                    Res::Draw
                } else {
                    Res::Lose
                }
            }
            _ => {
                panic!()
            }
        };

        self.cache[left][right].clone()
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for _ in 0..test_case {
        let s = input.next().unwrap();
        let mut dp = DP::new(s);
        let res = dp.solve(0, s.len());

        writeln!(
            stdout,
            "{}",
            match res {
                Res::None => panic!(),
                Res::Win => "Alice",
                Res::Draw | Res::DrawWithChar(_) => "Draw",
                Res::Lose => "Bob",
            }
        )
        .ok();
    }
}
