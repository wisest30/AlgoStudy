use std::io::{stdin, Read};

fn main() {
    let mut stdin = stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let test_case = input.next().unwrap().parse::<usize>().unwrap();

    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();

        let mut v = (0..n)
            .map(|_| input.next().unwrap().parse::<i32>().unwrap())
            .collect::<Vec<_>>();

        v.sort_unstable();

        let mut ans = 0.0;
        for _ in 0..m - 1 {
            ans += v.pop().unwrap() as f64;
        }

        ans += if v.len() % 2 == 0 {
            (v[v.len() / 2 - 1] + v[v.len() / 2]) as f64 / 2.0
        } else {
            v[v.len() / 2] as f64
        };

        println!("Case #{}: {:.1}", tc, ans);
    }
}
