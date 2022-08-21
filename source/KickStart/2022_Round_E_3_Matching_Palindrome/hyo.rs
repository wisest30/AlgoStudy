use std::io::Read;

fn manacher(s: &Vec<char>) -> Vec<i32> {
    let n = s.len();
    let mut right = -1;
    let mut j = -1;
    let mut dp = vec![0; n];
    for i in 0..n {
        let i = i as i32;
        if i <= right {
            dp[i as usize] = std::cmp::min(dp[(2 * j - i) as usize], right - i);
        }
        while i - dp[i as usize] - 1 >= 0
            && i + dp[i as usize] + 1 < n as i32
            && s[(i - dp[i as usize] - 1) as usize] == s[(i + dp[i as usize] + 1) as usize]
        {
            dp[i as usize] += 1;
        }
        if i + dp[i as usize] > right {
            right = i + dp[i as usize];
            j = i;
        }
    }

    dp
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let test_case_count = input.next().unwrap().parse::<usize>().unwrap();
    for test_case in 1..=test_case_count {
        let n = input.next().unwrap().parse::<usize>().unwrap();

        let s = input.next().unwrap().chars().collect::<Vec<char>>();
        let dp = manacher(&s);

        let mut sx = vec!['.'; 2 * n - 1];
        for i in 0..n {
            sx[i * 2] = s[i];
        }
        let dpx = manacher(&sx);

        let is_pd_prefix = |len: usize| {
            if len % 2 == 0 {
                let i = len - 1;
                i as i32 == dpx[i]
            } else {
                let i = len / 2;
                i as i32 == dp[i]
            }
        };

        let is_pd_suffix = |len: usize| {
            if len % 2 == 0 {
                let i = dpx.len() - len;
                dpx.len() - i - 1 == dpx[i] as usize
            } else {
                let i = n - len / 2 - 1;
                n - i - 1 == dp[i] as usize
            }
        };

        let mut ans = s.iter().collect::<String>();
        for i in 1..n {
            if is_pd_prefix(i) && is_pd_suffix(n - i) {
                ans = s.iter().take(i).collect::<String>();
                break;
            }
        }

        println!("Case #{}: {}", test_case, ans);
    }
}
