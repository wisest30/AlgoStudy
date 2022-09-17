use std::io::Read;

const MOD: i64 = 1_000_000_007;
fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<i64>().unwrap();
        let tree = (0..n)
            .map(|_| {
                (
                    input.next().unwrap().parse::<i64>().unwrap(),
                    input.next().unwrap().parse::<i64>().unwrap(),
                )
            })
            .collect::<Vec<_>>();

        let q = input.next().unwrap().parse::<i64>().unwrap();
        let well = (0..q)
            .map(|_| {
                (
                    input.next().unwrap().parse::<i64>().unwrap(),
                    input.next().unwrap().parse::<i64>().unwrap(),
                )
            })
            .collect::<Vec<_>>();

        let mut ss_x = 0;
        let mut s_x = 0;
        let mut ss_y = 0;
        let mut s_y = 0;

        for t in &tree {
            ss_x += t.0 * t.0 % MOD;
            ss_x %= MOD;

            s_x += t.0;
            s_x %= MOD;

            ss_y += t.1 * t.1 % MOD;
            ss_y %= MOD;

            s_y += t.1;
            s_y %= MOD;
        }

        let mut ret = 0i64;
        for w in well {
            ret += ss_x;
            ret %= MOD;

            ret += MOD - (2 * s_x * w.0 % MOD);
            ret %= MOD;

            ret += n * w.0 % MOD * w.0 % MOD;
            ret %= MOD;

            ret += ss_y;
            ret %= MOD;

            ret += MOD - (2 * s_y * w.1 % MOD);
            ret %= MOD;

            ret += n * w.1 % MOD * w.1 % MOD;
            ret %= MOD;
        }

        println!("Case #{tc}: {ret}");
    }
}
