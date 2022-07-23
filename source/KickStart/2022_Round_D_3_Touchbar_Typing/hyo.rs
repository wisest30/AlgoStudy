use std::cmp::min;
use std::io::{stdin, Read};

fn lower_bound(v: &Vec<usize>, val: usize) -> usize {
    if v.is_empty() || val <= v[0] {
        0
    } else if *v.last().unwrap() < val {
        v.len()
    } else {
        let mut l = 0;
        let mut r = v.len();

        while l + 1 < r {
            let m = (l + r) / 2;
            if val <= v[m] {
                r = m;
            } else {
                l = m;
            }
        }

        r
    }
}

fn main() {
    let mut stdin = stdin();
    let mut buf = String::new();
    stdin.read_to_string(&mut buf).ok();

    let mut input = buf.split_ascii_whitespace();
    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let s = (0..n)
            .map(|_| input.next().unwrap().parse::<i32>().unwrap())
            .collect::<Vec<_>>();

        let m = input.next().unwrap().parse::<usize>().unwrap();
        let k = (0..m)
            .map(|_| input.next().unwrap().parse::<i32>().unwrap())
            .collect::<Vec<_>>();

        let mut idxs = vec![Vec::new(); 2501];
        for (i, &val) in k.iter().enumerate() {
            idxs[val as usize].push(i);
        }

        let mut dp = (0..m)
            .map(|i| if k[i] == s[0] { 0 } else { std::i32::MAX })
            .collect::<Vec<_>>();

        for i in 1..n {
            let mut ndp = vec![std::i32::MAX; m];
            for &j in idxs[s[i] as usize].iter() {
                let v = &idxs[s[i - 1] as usize];
                let p = lower_bound(v, j);
                if p < v.len() && dp[v[p]] != std::i32::MAX {
                    ndp[j] = (j as i32 - v[p] as i32).abs() + dp[v[p]];
                }
                if p > 0 {
                    let p = p - 1;
                    if dp[v[p]] != std::i32::MAX {
                        ndp[j] = min(ndp[j], (j as i32 - v[p] as i32).abs() + dp[v[p]]);
                    }
                }
            }

            dp = ndp;
        }

        let ans = dp.into_iter().min().unwrap();
        println!("Case #{}: {}", tc, ans);
    }
}
