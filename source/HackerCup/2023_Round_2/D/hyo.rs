use std::{
    collections::HashMap,
    io::{Read, Write},
};

struct Combination2 {
    mo: i64, // mod should be prime number and mod > n
    fact: Vec<i64>,
}

impl Combination2 {
    pub fn new(n: usize, mo: i64) -> Self {
        let mut fact = vec![0; n + 1];
        fact[0] = 1;
        for i in 1..=n {
            fact[i] = (fact[i - 1] * i as i64) % mo;
        }

        Self { mo, fact }
    }

    fn pow_mod(&self, mut x: i64, mut y: i64) -> i64 {
        let mut ret = 1;
        while y > 0 {
            if y & 1 == 1 {
                ret = (ret * x) % self.mo;
            }
            x = (x * x) % self.mo;
            y >>= 1;
        }
        ret
    }

    pub fn ncr(&self, n: usize, r: usize) -> i64 {
        let mut ret = self.fact[n];
        ret = (ret * self.pow_mod(self.fact[n - r], self.mo - 2)) % self.mo;
        ret = (ret * self.pow_mod(self.fact[r], self.mo - 2)) % self.mo;
        ret
    }
}

fn get_minimum_prime_factors(n: i64) -> Vec<i64> {
    let mut minimum_prime_factor = vec![0; (n + 1) as usize];
    let mut primes = Vec::new();
    for i in 2..=n {
        if minimum_prime_factor[i as usize] == 0 {
            minimum_prime_factor[i as usize] = i;
            primes.push(i);
        }
        for &prime in primes.iter() {
            let j = i * prime;
            if j > n || prime > minimum_prime_factor[i as usize] {
                break;
            }
            minimum_prime_factor[j as usize] = prime;
        }
    }

    minimum_prime_factor
}

fn mobius_function(n: i64) -> Vec<i64> {
    let minimum_prime_factor = get_minimum_prime_factors(n);
    let mut mobius_function = vec![0; (n + 1) as usize];
    mobius_function[1] = 1;
    for i in 2..=n {
        let j = i / minimum_prime_factor[i as usize];
        if minimum_prime_factor[i as usize] == minimum_prime_factor[j as usize] {
            mobius_function[i as usize] = 0;
        } else {
            mobius_function[i as usize] = -mobius_function[j as usize];
        }
    }
    mobius_function
}

fn get_divisors(n: usize) -> Vec<Vec<i64>> {
    let mut divisors = vec![vec![]; n + 1];
    for i in 1..=n {
        for j in (i..=n).step_by(i) {
            divisors[j].push(i as i64);
        }
    }
    divisors
}

const MAX_N: usize = 1000000;
const MAX_H: usize = 1000000;
const MOD: i64 = 1000000007;

struct Problem<'a> {
    comb: &'a Combination2,
    mobius: &'a Vec<i64>,
    divisors: &'a Vec<Vec<i64>>,
    mo: i64,
    _n: usize,
    k: usize,
    d: usize,
    h: Vec<usize>,
}

impl<'a> Problem<'a> {
    fn new(
        comb: &'a Combination2,
        mobius: &'a Vec<i64>,
        divisors: &'a Vec<Vec<i64>>,
        mo: i64,
        n: usize,
        k: usize,
        d: usize,
        h: Vec<usize>,
    ) -> Self {
        Self {
            comb,
            mobius,
            divisors,
            mo,
            _n: n,
            k,
            d,
            h,
        }
    }

    fn solve(&mut self) -> i64 {
        let mut cnts = HashMap::new();
        self.h
            .iter()
            .flat_map(|&h| &self.divisors[h])
            .for_each(|&d| {
                *cnts.entry(d).or_insert(0) += 1;
            });

        let mut ans = 0;
        for &d in &self.divisors[self.d] {
            for i in 1.. {
                let id = i * d;
                if id > MAX_H as i64 {
                    break;
                }

                let cnt = *cnts.get(&id).unwrap_or(&0);
                if cnt < self.k {
                    continue;
                }

                let c = self.comb.ncr(cnt, self.k);
                let m = self.mobius[i as usize];
                ans = (ans + c * m + self.mo) % self.mo;
            }
        }

        for i in 1..=self.k as i64 {
            ans = ans * i % self.mo;
        }

        ans
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    // initialize
    let comb = Combination2::new(MAX_N, MOD);
    let mobius = mobius_function(MAX_N as i64);
    let divisors = get_divisors(MAX_N);

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let k = input.next().unwrap().parse::<usize>().unwrap();
        let d = input.next().unwrap().parse::<usize>().unwrap();
        let h = (0..n)
            .map(|_| input.next().unwrap().parse::<usize>().unwrap())
            .collect::<Vec<_>>();

        let mut prob = Problem::new(&comb, &mobius, &divisors, MOD, n, k, d, h);
        let ans = prob.solve();

        writeln!(stdout, "Case #{tc}: {}", ans).ok();
    }
}
