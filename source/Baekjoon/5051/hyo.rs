use std::collections::HashMap;
use std::io::{Read, Write};
use std::ops::{Add, Div, Mul, Sub};

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

fn fft(mut a: Vec<Complex<f64>>, invert: bool) -> Vec<Complex<f64>> {
    use std::f64::consts::PI;

    fn reverse(num: usize, lg_n: usize) -> usize {
        (0..lg_n)
            .filter(|i| (num & (1 << i)) != 0)
            .map(|i| 1 << (lg_n - 1 - i))
            .fold(0usize, |acc, x| acc ^ x)
    }

    let mut lg_n = 0usize;
    while (1 << lg_n) < a.len() {
        lg_n += 1;
    }

    if a.len() < (1 << lg_n) {
        a.resize(1 << lg_n, Complex::new(0.0, 0.0));
    }

    for i in 0..a.len() {
        let j = reverse(i, lg_n);
        if i < j {
            (a[i], a[j]) = (a[j], a[i]);
        }
    }

    let mut len = 2;
    while len <= a.len() {
        let ang = 2.0 * PI / len as f64 * if invert { -1.0 } else { 1.0 };
        let w = Complex::new(f64::cos(ang), f64::sin(ang));
        for i in (0..a.len()).step_by(len) {
            let mut w_pow = Complex::new(1.0, 0.0);
            for j in 0..len / 2 {
                let (u, v) = (a[i + j], a[i + j + len / 2] * w_pow);
                (a[i + j], a[i + j + len / 2]) = (u + v, u - v);
                w_pow = w_pow * w;
            }
        }

        len <<= 1;
    }

    if invert {
        let a_len = a.len() as f64;
        for x in &mut a {
            x.real /= a_len;
            x.im /= a_len;
        }
    }

    a
}

struct Problem {
    n: usize,
}

impl Problem {
    fn new(n: usize) -> Self {
        Problem { n }
    }

    fn generate_v(&self) -> Vec<i64> {
        (1..self.n as i64)
            .map(|x| x * x)
            .map(|x| x % self.n as i64)
            .collect::<Vec<_>>()
    }

    fn generate_count_map(&self, v: &[i64]) -> HashMap<i64, i64> {
        let mut ret = HashMap::new();
        for x in v {
            *ret.entry(*x).or_insert(0) += 1;
        }

        ret
    }

    fn calculate_same_ab(&self, v: &[i64], v_count_map: &HashMap<i64, i64>) -> i64 {
        v.iter()
            .map(|x| 2 * x % self.n as i64)
            .map(|double_x| v_count_map.get(&double_x).unwrap_or(&0))
            .sum()
    }

    fn generate_a(&self, v: &[i64]) -> Vec<Complex<f64>> {
        let mut size = 1usize;
        while size <= v.len() {
            size <<= 1;
        }
        size <<= 1;

        let mut a = vec![Complex::new(0.0, 0.0); size];
        for x in v {
            a[*x as usize].real += 1.0;
        }
        a
    }

    fn solve(&self) -> i64 {
        let v = self.generate_v();
        let v_count_map = self.generate_count_map(&v);
        let same_ab_cnt = self.calculate_same_ab(&v, &v_count_map);
        let a = self.generate_a(&v);
        let a_fft = fft(a, false);
        let c_fft = a_fft.into_iter().map(|x| x * x).collect::<Vec<_>>();
        let c = fft(c_fft, true);
        let res = c
            .into_iter()
            .map(|x| x.real.round() as i64)
            .enumerate()
            .map(|(i, x)| x * v_count_map.get(&((i % self.n) as i64)).unwrap_or(&0))
            .sum::<i64>();

        (res + same_ab_cnt) / 2
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let ans = Problem::new(n).solve();

    writeln!(stdout, "{}", ans).ok();
}
