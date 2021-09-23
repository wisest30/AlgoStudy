#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
use std::collections::HashMap;
 
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
fn ccw(a: (i64, i64), b: (i64, i64)) -> i32 {
    let v1 = (-a.0, -a.1);
    let v2 = (b.0 - a.0, b.1 - a.1);

    let p = v1.0 * v2.1 - v1.1 * v2.0;
    if p > 0 {
        1
    } else if p == 0 {
        0
    } else {
        -1
    }
}

fn dis(a: (i64, i64), b: (i64, i64)) -> f64 {
    (((a.0 - b.0).pow(2) + (a.1 - b.1).pow(2)) as f64).sqrt()
}

fn gcd(a: i64, b: i64) -> i64 {
    if a < 0 || b < 0 {
        gcd(a.abs(), b.abs())
    } else if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn make_key(x: i64, y: i64) -> (i64, i64) {
    let g = gcd(x, y);
    let a = if y == 0 { x / x.abs() } else { x / g };
    let b = if x == 0 { y / y.abs() } else { y / g };

    (a, b)
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let test_case = scan.next::<usize>();
    for tc in 1..=test_case {
        let n = scan.next::<usize>();
        let mut v = Vec::with_capacity(n);
        for _ in 0..n {
            let x = scan.next::<i64>();
            let y = scan.next::<i64>();
            v.push((x, y));
        }

        let x = scan.next::<i64>();
        let y = scan.next::<i64>();

        for p in &mut v {
            *p = (p.0 - x, p.1 - y);
        }

        let inf = 1e50;
        let mut ans = inf;
        for i in 0..n {
            for j in i+1..n {
                for k in j+1..n {
                    let p = ccw(v[i], v[j]);
                    if p != 0 && p == ccw(v[j], v[k]) && p == ccw(v[k], v[i]) {
                        let d = dis(v[i], v[j]) + dis(v[j], v[k]) + dis(v[k], v[i]);
                        if d < ans {
                            ans = d;
                        }
                    }
                }
            }
        }

        let mut m = HashMap::new();
        for i in 0..n {
            if v[i] == (0, 0) {
                continue;
            }

            let key = make_key(v[i].0, v[i].1);
            let r = dis((0, 0), v[i]);
            let p = m.entry(key).or_insert(n);
            if *p == n || r < dis((0, 0), v[*p]) {
                *p = i;
            }
        }

        for (&(x0, y0), &i0) in &m {
            let x1 = -x0;
            let y1 = -y0;

            if m.contains_key(&(x1, y1)) == false || y0 < 0 || y0 == 0 && x0 < 0 {
                continue;
            }

            let &i1 = m.get(&(x1, y1)).unwrap();
            
            for (&(x2, y2), &i2) in &m {
                let x3 = -x2;
                let y3 = -y2;

                if m.contains_key(&(x3, y3)) == false || y2 < 0 || y2 == 0 && x2 < 0 || i0 == i2 {
                    continue;
                }

                let &i3 = m.get(&(x3, y3)).unwrap();

                let d = dis(v[i0], v[i2]) + dis(v[i2], v[i1]) + dis(v[i1], v[i3]) + dis(v[i3], v[i0]);
                if d < ans {
                    ans = d;
                }
            }
        }

        if ans == inf {
            writeln!(out, "Case #{}: IMPOSSIBLE", tc).ok();
        } else {
            writeln!(out, "Case #{}: {:.15}", tc, ans).ok();
        }
    }
}
