#[allow(unused_imports)]
use std::{
    io::{BufWriter, stdin, stdout, Write},
    str::FromStr, cmp::{min,max,Ordering},
    collections::HashMap,
};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}

#[allow(dead_code)]
impl Scanner {
    fn next<T: FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("parse fail");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("read fail");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }

    pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
        (0..len).map(|_| self.next()).collect()
    }
}

///////////////////////////////////////////////////////////////////////////////
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let test_case = scan.next::<usize>();
    for tc in 1..=test_case {
        let n = scan.next::<usize>();
        let m = scan.next::<usize>();

        let a = scan.next_vec::<i32>(m);
        let mut a = a.iter().cloned().zip(vec![true; m]).collect::<Vec<_>>();

        let mut ans = 0;
        for _ in 0..n {
            let mut b = scan.next_vec::<i32>(m);
            a.sort();
            b.sort();

            let mut i = 0;
            let mut j = 0;
            let mut nxt_a = Vec::new();
            while i < m || j < m {
                let status = if i == m {
                    1
                } else if j == m {
                    0
                } else {
                    match a[i].0.cmp(&b[j]) {
                        Ordering::Less => 0,
                        Ordering::Greater => 1,
                        Ordering::Equal => 2
                    }
                };

                match status {
                    0 => {
                        ans -= if a[i].1 {1} else {0};
                        i += 1;
                    }
                    1 => {
                        ans += 1;
                        nxt_a.push((b[j], false));
                        j += 1;
                    }
                    2 => {
                        nxt_a.push(a[i]);
                        i += 1;
                        j += 1;
                    }
                    _ => {}
                }
            }

            a = nxt_a;
        }

        writeln!(out, "Case #{}: {}", tc, ans).expect("wrong write");
    }
}
