#[allow(unused_imports)]
use std::{
    io::{BufWriter, stdin, stdout, Write},
    str::FromStr, cmp::{min,max,Ordering},
    collections::HashMap,
    collections::HashSet,
    cell::{Cell, RefCell, RefMut},
    rc::Rc,
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
    let test_cases = scan.next::<usize>();

    for tc in 1..=test_cases {
        let s = scan.next::<String>();
        let f = scan.next::<String>();

        let cost: Vec<i32> = (b'a'..=b'z').map(|c1| f.chars().map(|c2| min((c1 as i32 - c2 as i32).abs(), 26 - (c1 as i32 - c2 as i32).abs())).min().unwrap()).collect();
        let ans: i32 = s.chars().map(|x| cost[x as usize - 'a' as usize]).sum();

        writeln!(out, "Case #{}: {}", tc, ans).ok();
    }
}
