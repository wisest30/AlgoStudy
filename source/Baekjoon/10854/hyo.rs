use std::io::{Read, Write};

type T = i128;

mod random {
    pub fn init() {
        unsafe { srand(time(std::ptr::null()) as u32) };
    }

    pub fn gen() -> i32 {
        unsafe { rand() }
    }

    #[link(name = "c")]
    extern "C" {
        fn time(timer: *const u64) -> u64;
        fn srand(seed: u32);
        fn rand() -> i32;
    }
}

fn pow_mod(mut x: T, mut exp: T, m: T) -> T {
    let mut ret = 1;
    while exp > 0 {
        if exp & 1 == 1 {
            ret = ret * x % m;
        }
        x = x * x % m;
        exp >>= 1;
    }
    ret
}

fn miller_rabin(n: T) -> bool {
    let primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41];
    if primes.contains(&n) {
        return true;
    }
    if n == 1 || n % 2 == 0 {
        return false;
    }

    primes.iter().all(|&prime| {
        let mut d = n - 1;
        while d % 2 == 0 {
            if pow_mod(prime, d, n) == n - 1 {
                return true;
            }
            d /= 2;
        }
        let tmp = pow_mod(prime, d, n);
        tmp == n - 1 || tmp == 1
    })
}

fn gcd(mut x: T, mut y: T) -> T {
    while y > 0 {
        x = x % y;
        std::mem::swap(&mut x, &mut y);
    }
    x
}

fn pollard_rho(mut n: T) -> T {
    'outer: loop {
        if n == 1 {
            return n;
        }
        if n % 2 == 0 {
            return 2;
        }
        if miller_rabin(n) {
            return n;
        }
        let mut x = random::gen() as T % (n - 2) + 2;
        let mut y = x;
        let c = random::gen() as T % 10 + 1;
        let mut g = 1;
        while g == 1 {
            x = (x * x + c) % n;
            y = (y * y + c) % n;
            y = (y * y + c) % n;
            g = gcd((x - y).abs(), n);
            if g == n {
                continue 'outer;
            }
        }
        if miller_rabin(g) {
            return g;
        } else {
            n = g;
        }
    }
}

struct Problem {
    n: i128
}

impl Problem {
    fn new(n: i128) -> Self {
        Self {
            n,
        }
    }

    fn solve(&mut self) -> i128 {
        random::init();
        let mut map = std::collections::HashMap::new();
        while self.n > 1 {
            let d = pollard_rho(self.n);
            self.n /= d;
            *map.entry(d).or_insert(0) += 1;
        }

        map.values().fold(1i128, |acc, x| acc * (x + 1))
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<i128>().unwrap();
    let ans = Problem::new(n).solve();

    writeln!(stdout, "{}", ans).ok();
}
