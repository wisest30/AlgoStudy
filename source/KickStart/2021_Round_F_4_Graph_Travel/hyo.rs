#[allow(unused_imports)]
use std::{
    io::{BufWriter, stdin, stdout, Write},
    str::FromStr, cmp::{min,max},
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
#[derive(Debug)]
struct Room {
    l: i64,
    r: i64,
    a: i64,
}

#[derive(Debug)]
struct Corridor {
    u: usize,
    v: usize,
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let test_case = scan.next::<usize>();
    for tc in 1..=test_case {
        let n = scan.next::<usize>();
        let m = scan.next::<usize>();
        let k = scan.next::<i64>();

        let rooms: Vec<Room> = (0..n).map(|_| 
            Room{l: scan.next::<i64>(), r: scan.next::<i64>(), a: scan.next::<i64>()}
        ).collect();

        let corridors: Vec<Corridor> = (0..m).map(|_|
            Corridor{u: scan.next::<usize>(), v: scan.next::<usize>()}
        ).collect();

        let mut g = vec![Vec::new(); n];
        for corr in &corridors {
            g[corr.u].push(corr.v);
            g[corr.v].push(corr.u);
        }

        let mut dp = vec![0i64; 1 << n];
        for i in 0..n {
            dp[1 << i] = 1;
        }

        let mut ans = 0;
        for subset in 1..1<<n {
            let cur_k: i64 = (0..n).map(|i| if (subset & (1 << i)) != 0 { rooms[i].a } else { 0 })
                            .collect::<Vec<i64>>().iter().sum();

            if cur_k == k {
                ans += dp[subset];
            }

            let mut visited = vec![false; n];
            for i in 0..n {
                if (subset & (1 << i)) != 0 {
                    for &nxt in &g[i] {
                        if visited[nxt] == false && (subset & (1 << nxt)) == 0 && rooms[nxt].l <= cur_k && cur_k <= rooms[nxt].r {
                            dp[subset | (1 << nxt)] += dp[subset];
                            visited[nxt] = true;
                        }
                    }
                }
            }
        }

        writeln!(out, "Case #{}: {}", tc, ans).ok();
    }
}
