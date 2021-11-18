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
        let _n = scan.next::<usize>();
        let s = scan.next::<String>();

        let colors = s.chars().map(|x| match x {
            'R' => 0b001,
            'Y' => 0b010,
            'B' => 0b100,
            'O' => 0b011,
            'P' => 0b101,
            'G' => 0b110,
            'A' => 0b111,
            _ => 0b000
        }).collect::<Vec<u8>>();

        let mut r = colors.iter().map(|x| x & 0b001).collect::<Vec<u8>>();
        r.dedup();

        let mut y = colors.iter().map(|x| x & 0b010).collect::<Vec<u8>>();
        y.dedup();

        let mut b = colors.iter().map(|x| x & 0b100).collect::<Vec<u8>>();
        b.dedup();

        let ans = r.iter().filter(|x| **x != 0).count() + y.iter().filter(|x| **x != 0).count() + b.iter().filter(|x| **x != 0).count();
        writeln!(out, "Case #{}: {}", tc, ans).ok();
    }
}
