use std::io::{Read, Write};

const MIN_NUM: i64 = 50;
const MAX_NUM: i64 = 2_000_000_000;

struct Problem {
    k: i64,
    small_primes: Vec<i64>,
    big_square_nums: Vec<i64>,
}

impl Problem {
    fn new(k: i64) -> Self {
        let small_primes = Problem::generate_small_primes();
        let big_square_nums = Problem::generate_big_square_nums(&small_primes);

        Self {
            k,
            small_primes,
            big_square_nums,
        }
    }

    fn generate_small_primes() -> Vec<i64> {
        let mut ret = Vec::new();
        'outer: for i in 2..MIN_NUM {
            for j in 2..i {
                if i % j == 0 {
                    continue 'outer;
                }
            }

            ret.push(i);
        }

        ret
    }

    // except divisible by square of small primes
    fn generate_big_square_nums(small_primes: &[i64]) -> Vec<i64> {
        let mut ret = Vec::new();
        'outer: for i in MIN_NUM.. {
            if i * i > MAX_NUM {
                break;
            }

            for &prime in small_primes {
                if i % prime == 0 {
                    continue 'outer;
                }
            }

            let mut j = i * i;
            while j <= MAX_NUM {
                ret.push(j);
                j += i * i;
            }
        }

        ret.sort_unstable();
        ret.dedup();
        ret.retain(|&x| small_primes.iter().all(|&p| x % (p * p) != 0));

        ret
    }

    fn solve(&mut self) -> i64 {
        let mut left = 0;
        let mut right = MAX_NUM;
        while left + 1 < right {
            let mid = (left + right) / 2;

            if mid - self.count_square_nums(mid) >= self.k {
                right = mid;
            } else {
                left = mid;
            }
        }

        right
    }

    fn count_square_nums(&self, n: i64) -> i64 {
        let mut ret = self.big_square_nums.iter().filter(|&&x| x <= n).count() as i64;

        let prime_count = self.small_primes.len();
        'outer: for subset in 1i64..(1 << prime_count) {
            let count_ones = subset.count_ones();

            let mut mul = 1i64;
            for i in 0..prime_count {
                if subset & (1 << i) != 0 {
                    let mul_opt = mul.checked_mul(self.small_primes[i] * self.small_primes[i]);
                    if let Some(res) = mul_opt {
                        mul = res;
                    } else {
                        continue 'outer;
                    }
                }
            }

            ret += n / mul * if count_ones % 2 == 0 { -1 } else { 1 };
        }

        ret
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let k = input.next().unwrap().parse::<i64>().unwrap();
    let ans = Problem::new(k).solve();

    writeln!(stdout, "{}", ans).ok();
}
