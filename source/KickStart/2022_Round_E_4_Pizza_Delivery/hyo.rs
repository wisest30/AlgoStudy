use std::{cmp::max, io::Read, str::SplitAsciiWhitespace};

const NAN: i64 = std::i64::MIN;
const NAN_CACHED: i64 = NAN + 1;

struct Context {
    n: usize,
    p: usize,
    m: usize,
    ar: usize,
    ac: usize,
    // {North,East,West,South} coin caculate function
    func: Vec<Box<dyn Fn(i64) -> i64>>,
    // customer_info[r][c] = (index, coin)
    customer_info: Vec<Vec<(usize, i64)>>,
}

impl Context {
    fn new(input: &mut SplitAsciiWhitespace) -> Self {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let p = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();
        let ar = input.next().unwrap().parse::<usize>().unwrap();
        let ac = input.next().unwrap().parse::<usize>().unwrap();

        let mut func = Vec::new();

        for _ in 0..4 {
            let op = input.next().unwrap().parse::<char>().unwrap();
            let k = input.next().unwrap().parse::<i64>().unwrap();

            let f = move |coin: i64| {
                if coin == NAN {
                    NAN
                } else {
                    match op {
                        '+' => coin + k,
                        '-' => coin - k,
                        '/' => {
                            if coin >= 0 || coin % k == 0 {
                                coin / k
                            } else {
                                coin / k - 1
                            }
                        }
                        '*' => coin * k,
                        _ => panic!("wrong input."),
                    }
                }
            };

            func.push(Box::new(f) as Box<dyn Fn(i64) -> i64>);
        }

        let mut customer_info = vec![vec![(0, NAN); n + 1]; n + 1];
        for i in 0..p {
            let r = input.next().unwrap().parse::<usize>().unwrap();
            let c = input.next().unwrap().parse::<usize>().unwrap();
            let coin = input.next().unwrap().parse::<i64>().unwrap();
            customer_info[r][c] = (i, coin);
        }

        Context {
            n,
            p,
            m,
            ar,
            ac,
            func,
            customer_info,
        }
    }
}

fn recur(
    subset: usize,
    time: usize,
    r: usize,
    c: usize,
    dp: &mut Vec<Vec<Vec<Vec<i64>>>>,
    ctx: &Context,
) -> i64 {
    if time == 0 {
        return if r == ctx.ar && c == ctx.ac && subset == (1 << ctx.p) - 1 {
            0
        } else {
            NAN
        };
    }

    if dp[subset][time][r][c] != NAN_CACHED {
        return dp[subset][time][r][c];
    }

    let mut ret = recur(subset, time - 1, r, c, dp, ctx);

    if ctx.customer_info[r][c].1 != NAN {
        let (i, coin) = ctx.customer_info[r][c];
        if (subset & (1 << i)) == 0 {
            let sub_ret = recur(subset ^ (1 << i), time, r, c, dp, ctx);
            if sub_ret != NAN {
                ret = max(ret, sub_ret + coin);
            }
        }
    }

    const DR: [i32; 4] = [-1, 0, 0, 1];
    const DC: [i32; 4] = [0, 1, -1, 0];

    for i in 0..4 {
        let nr = (r as i32 + DR[i]) as usize;
        let nc = (c as i32 + DC[i]) as usize;

        if nr < 1 || nr > ctx.n || nc < 1 || nc > ctx.n {
            continue;
        }

        let sub_ret = recur(subset, time - 1, nr, nc, dp, ctx);
        if sub_ret == NAN {
            continue;
        }

        let j = match i {
            0 => 3,
            1 => 2,
            2 => 1,
            3 => 0,
            _ => panic!(),
        };

        ret = max(ret, ctx.func[j](sub_ret));
    }

    dp[subset][time][r][c] = ret;
    ret
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let test_case_count = input.next().unwrap().parse::<usize>().unwrap();
    for test_case in 1..=test_case_count {
        let ctx = Context::new(&mut input);
        let mut dp =
            vec![vec![vec![vec![NAN_CACHED; ctx.n + 1]; ctx.n + 1]; ctx.m + 1]; 1 << ctx.p];

        let mut ans = NAN;

        for r in 1..=ctx.n {
            for c in 1..=ctx.n {
                ans = max(ans, recur(0, ctx.m, r, c, &mut dp, &ctx));
            }
        }

        if ans == NAN {
            println!("Case #{}: IMPOSSIBLE", test_case);
        } else {
            println!("Case #{}: {}", test_case, ans);
        }
    }
}
