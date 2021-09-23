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
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let test_case = scan.next::<usize>();
    for tc in 1..=test_case {
        let n = scan.next::<usize>();
        let s = scan.next::<String>();
        let v: Vec<bool> = s.chars().map(|ch| ch == '1').collect();

        let inf = (n + 10) as i64;
        let mut dis = vec![inf; n];
        let mut left = None;
        for i in 0..n {
            if v[i] {
                left = Some(i);
                dis[i] = 0;
            } else if left != None {
                dis[i] = (i - left.unwrap()) as i64;
            }
        }
        let mut right = None;
        for i in (0..n).rev() {
            if v[i] {
                right = Some(i);
            } else if right != None {
                dis[i] = min(dis[i], (right.unwrap() - i) as i64);
            }
        }

        let ans:i64 = dis.iter().sum();
        writeln!(out, "Case #{}: {}", tc, ans).ok();
    }
}
