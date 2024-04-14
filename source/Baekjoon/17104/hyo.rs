use std::io::{Read, Write};
use std::ops::{Add, Div, Mul, Sub};

const MAX_N: usize = 1usize << 20;

#[derive(Debug, Copy, Clone, PartialEq)]
struct Complex<T> {
    real: T,
    im: T,
}

impl<T: Add<Output = T>> Add for Complex<T> {
    type Output = Self;

    fn add(self, other: Self) -> Self {
        Self {
            real: self.real + other.real,
            im: self.im + other.im,
        }
    }
}

impl<T> Sub for Complex<T>
where
    T: Sub<Output = T>,
{
    type Output = Self;

    fn sub(self, other: Self) -> Self {
        Self {
            real: self.real - other.real,
            im: self.im - other.im,
        }
    }
}

impl<T> Mul for Complex<T>
where
    T: Add<Output = T> + Sub<Output = T> + Mul<Output = T> + Copy,
{
    type Output = Self;

    fn mul(self, other: Self) -> Self {
        Self {
            real: self.real * other.real - self.im * other.im,
            im: self.real * other.im + self.im * other.real,
        }
    }
}

impl<T> Div for Complex<T>
where
    T: Add<Output = T> + Sub<Output = T> + Mul<Output = T> + Div<Output = T> + Copy,
{
    type Output = Self;

    fn div(self, other: Self) -> Self {
        let p = other.real * other.real + other.im * other.im;
        Self {
            real: (self.real * other.real + self.im * other.im) / p,
            im: (self.im * other.real - self.real * other.im) / p,
        }
    }
}

impl<T> Complex<T> {
    fn new(real: T, im: T) -> Complex<T> {
        Self { real, im }
    }
}

// assert size of 'a' is 2 ^ (n + 1). {original vector size} <= 2 ^ n.
// x0 : 1의 n 제곱근.
// reference : https://m.blog.naver.com/kks227/221633584963
fn fft(mut a: Vec<Complex<f64>>, w: Complex<f64>) -> Vec<Complex<f64>> {
    if a.len() == 1 {
        return a;
    }

    let even = (0..a.len()).step_by(2).map(|i| a[i]).collect::<Vec<_>>();
    let odd = (1..a.len()).step_by(2).map(|i| a[i]).collect::<Vec<_>>();

    let even_fft = fft(even, w * w);
    let odd_fft = fft(odd, w * w);

    let mut w_pow = Complex::new(1.0, 0.0);
    let a_len = a.len();
    for i in 0..a.len() / 2 {
        a[i] = even_fft[i] + w_pow * odd_fft[i];
        a[i + a_len / 2] = even_fft[i] - w_pow * odd_fft[i];
        w_pow = w_pow * w;
    }

    a
}

fn idft(a: Vec<Complex<f64>>, w: Complex<f64>) -> Vec<Complex<f64>> {
    let mut a = fft(a, Complex::new(1.0, 0.0) / w);
    let p = Complex::new(a.len() as f64, 0.0);
    for i in 0..a.len() {
        a[i] = a[i] / p;
    }

    a
}

struct Problem {
    c: Vec<i64>,
}

pub fn get_primes(n: usize) -> Vec<i64> {
    let mut v = vec![true; n];
    let mut ret = Vec::new();
    for i in 2..n {
        if v[i] {
            ret.push(i as i64);
            for j in (2 * i..n).step_by(i) {
                v[j] = false;
            }
        }
    }

    ret
}

impl Problem {
    fn new() -> Self {
        Problem {
            c: Self::generate_c(),
        }
    }

    fn generate_c() -> Vec<i64> {
        use std::f64::consts::PI;

        let mut is_prime = vec![true; MAX_N];
        is_prime[0] = false;
        is_prime[1] = false;
        for i in 2..MAX_N {
            if is_prime[i] {
                for j in (2 * i..MAX_N).step_by(i) {
                    is_prime[j] = false;
                }
            }
        }

        let mut a = (0..MAX_N / 2)
            .map(|i| Complex::new(if is_prime[2 * i + 1] { 1.0 } else { 0.0 }, 0.0))
            .collect::<Vec<_>>();
        a.resize(MAX_N, Complex::new(0.0, 0.0));

        let n = a.len() as f64;
        let w = Complex::new(f64::cos(2.0 * PI / n), f64::sin(2.0 * PI / n));
        let a_fft = fft(a, w);
        let c_fft = a_fft.into_iter().map(|ai| ai * ai).collect::<Vec<_>>();
        let c = idft(c_fft, w);
        c.into_iter()
            .map(|c| c.real.round() as i64)
            .map(|x| x / 2 + x % 2)
            .collect::<Vec<_>>()
    }

    fn solve(&self, ns: Vec<usize>) -> String {
        ns.into_iter()
            .map(|n| n / 2 - 1)
            .map(|n| if n == 1 { 1 } else { self.c[n] }.to_string())
            .collect::<Vec<_>>()
            .join("\n")
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let t = input.next().unwrap().parse::<usize>().unwrap();
    let ns = (0..t)
        .map(|_| input.next().unwrap().parse::<usize>().unwrap())
        .collect::<Vec<_>>();
    let ans = Problem::new().solve(ns);

    writeln!(stdout, "{}", ans).ok();
}
