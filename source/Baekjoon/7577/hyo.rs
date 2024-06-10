use std::io::{Read, Write};

struct Problem {
    n: usize,
    k: usize,
    queries: Vec<(usize, usize, i32)>,
    psum: Vec<i32>,
}

impl Problem {
    fn new(n: usize, k: usize, queries: Vec<(usize, usize, i32)>) -> Self {
        Self {
            n,
            k,
            queries,
            psum: (0..k as i32 + 1).collect::<Vec<_>>(),
        }
    }

    fn refine_queries(&mut self) -> bool {
        let mut a = vec![Vec::new(); self.k];
        for q in &self.queries {
            a[q.0].push((q.1, q.2));
        }

        for i in 0..self.k {
            a[i].sort_unstable();
            let len = a[i].len();
            for j in 1..len {
                let left = a[i][0].0;
                let right = a[i][j].0;
                let cnt = a[i][j].1 - a[i][0].1;
                if cnt < 0 {
                    return false;
                }
                if left == right {
                    if cnt == 0 {
                        continue;
                    } else {
                        return false;
                    }
                }
                a[left].push((right, cnt));
            }
        }

        self.queries.clear();
        for i in 0..self.k {
            if !a[i].is_empty() {
                self.queries.push((i, a[i][0].0, a[i][0].1));
            }
        }

        true
    }

    fn solve(&mut self) -> String {
        if !self.refine_queries() {
            return "NONE".to_string();
        }

        loop {
            let mut conti = false;
            for &(left, right, cnt) in &self.queries {
                if self.psum[right] > self.psum[left] + cnt {
                    conti = true;
                    self.psum[right] = self.psum[left] + cnt;
                    for i in right + 1..=self.k {
                        self.psum[i] = self.psum[i].min(self.psum[i - 1] + 1);
                    }
                    for i in (0..right).rev() {
                        self.psum[i] = self.psum[i].min(self.psum[i + 1]);
                    }
                } else if self.psum[right] < self.psum[left] + cnt {
                    conti = true;
                    self.psum[left] = self.psum[right] - cnt;
                    for i in left + 1..=self.k {
                        self.psum[i] = self.psum[i].min(self.psum[i - 1] + 1);
                    }
                    for i in (0..left).rev() {
                        self.psum[i] = self.psum[i].min(self.psum[i + 1]);
                    }
                }

                if self.psum[0] < 0 {
                    return "NONE".to_string();
                }
            }

            if !conti {
                break;
            }
        }

        let mut ret = String::new();
        for i in 0..self.k {
            if self.psum[i] == self.psum[i + 1] {
                ret.push('-');
            } else {
                ret.push('#');
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
    let k = input.next().unwrap().parse::<usize>().unwrap();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let queries = (0..n)
        .map(|_| {
            (
                input.next().unwrap().parse::<usize>().unwrap() - 1,
                input.next().unwrap().parse::<usize>().unwrap(),
                input.next().unwrap().parse::<i32>().unwrap(),
            )
        })
        .collect::<Vec<_>>();

    let ans = Problem::new(n, k, queries).solve();

    writeln!(stdout, "{}", ans).ok();
}
