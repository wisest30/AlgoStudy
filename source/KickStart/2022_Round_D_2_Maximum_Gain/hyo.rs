use std::cmp::max;
use std::io::{stdin, Read};

fn get_max_sums(v: Vec<i64>, k: usize) -> Vec<i64> {
    let n = v.len();
    let mut max_sum = vec![0i64; k + 1];
    let mut left_sum = 0;
    for left in 0..=n {
        if left > 0 {
            left_sum += v[left - 1];
        }

        let mut right_sum = 0;
        for right in 0..=n {
            if right > 0 {
                right_sum += v[n - right];
            }

            let cnt = left + right;
            if cnt <= n && cnt <= k {
                max_sum[cnt] = max(max_sum[cnt], left_sum + right_sum);
            }
        }
    }

    max_sum
}

fn main() {
    let mut stdin = stdin();
    let mut buf = String::new();
    stdin.read_to_string(&mut buf).ok();

    let mut input = buf.split_ascii_whitespace();
    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let v0 = (0..n)
            .map(|_| input.next().unwrap().parse::<i64>().unwrap())
            .collect::<Vec<_>>();

        let m = input.next().unwrap().parse::<usize>().unwrap();
        let v1 = (0..m)
            .map(|_| input.next().unwrap().parse::<i64>().unwrap())
            .collect::<Vec<_>>();

        let k = input.next().unwrap().parse::<usize>().unwrap();

        let mut ans = 0i64;
        let max_sums0 = get_max_sums(v0, k);
        let max_sums1 = get_max_sums(v1, k);
        for cnt0 in 0..=k {
            let cnt1 = k - cnt0;
            ans = max(ans, max_sums0[cnt0] + max_sums1[cnt1]);
        }

        println!("Case #{}: {}", tc, ans);
    }
}
