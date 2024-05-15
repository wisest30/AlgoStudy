use std::io::{Read, Write};

enum Query {
    LagerThan(usize, usize, i32),
    Put(usize, i32),
}

const BOX_SIZE: usize = 1024;

struct Problem {
    n: usize,
    vals: Vec<i32>,
    q: usize,
    queries: Vec<Query>,
    sorted_box_vals: Vec<i32>,
}

impl Problem {
    fn new(n: usize, vals: Vec<i32>, q: usize, queries: Vec<Query>) -> Self {
        let sorted_box_vals = Self::construct_sorted_box_vals(&vals);
        Self {
            n,
            vals,
            q,
            queries,
            sorted_box_vals,
        }
    }

    fn construct_sorted_box_vals(vals: &Vec<i32>) -> Vec<i32> {
        let mut ret = vals.clone();
        for i in (0..ret.len()).step_by(BOX_SIZE) {
            ret[i..(i + BOX_SIZE).min(vals.len())].sort_unstable();
        }

        ret
    }

    fn solve(&mut self) -> String {
        let mut ret = String::new();
        for query in &self.queries {
            match query {
                &Query::LagerThan(mut i, mut j, k) => {
                    let mut count = 0;

                    while i < j && i % BOX_SIZE > 0 {
                        count += if self.vals[i] > k { 1 } else { 0 };
                        i += 1;
                    }

                    while i < j && j % BOX_SIZE > 0 {
                        count += if self.vals[j - 1] > k { 1 } else { 0 };
                        j -= 1;
                    }

                    let mut p = i;
                    while p < j {
                        count += p + BOX_SIZE - self.lower_bound(p, p + BOX_SIZE, k + 1);
                        p += BOX_SIZE;
                    }

                    ret += &count.to_string();
                    ret.push('\n');
                }
                &Query::Put(i, k) => {
                    let l = i / BOX_SIZE * BOX_SIZE;
                    let r: usize = self.sorted_box_vals.len().min(l + BOX_SIZE);

                    let p = self.lower_bound(l, r, self.vals[i]);
                    assert_ne!(p, self.sorted_box_vals.len());
                    assert_ne!(self.sorted_box_vals[p], k);
                    self.sorted_box_vals[p] = k;

                    let mut j = p;
                    while l < j && self.sorted_box_vals[j - 1] > self.sorted_box_vals[j] {
                        self.sorted_box_vals.swap(j - 1, j);
                        j -= 1;
                    }

                    j = p;
                    while j + 1 < r && self.sorted_box_vals[j] > self.sorted_box_vals[j + 1] {
                        self.sorted_box_vals.swap(j, j + 1);
                        j += 1;
                    }

                    self.vals[i] = k;
                }
            }
        }

        ret
    }

    fn lower_bound(&self, mut l: usize, mut r: usize, val: i32) -> usize {
        if self.sorted_box_vals[l] >= val {
            return l;
        }

        while l + 1 < r {
            let m = (l + r) / 2;
            if self.sorted_box_vals[m] < val {
                l = m;
            } else {
                r = m;
            }
        }

        r
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let vals = (0..n)
        .map(|_| input.next().unwrap().parse::<i32>().unwrap())
        .collect::<Vec<_>>();
    let q = input.next().unwrap().parse::<usize>().unwrap();
    let queries = (0..q)
        .map(|_| {
            let x = input.next().unwrap().parse::<i32>().unwrap();
            match x {
                1 => {
                    let i = input.next().unwrap().parse::<usize>().unwrap() - 1;
                    let j = input.next().unwrap().parse::<usize>().unwrap();
                    let k = input.next().unwrap().parse::<i32>().unwrap();
                    Query::LagerThan(i, j, k)
                }
                2 => {
                    let i = input.next().unwrap().parse::<usize>().unwrap() - 1;
                    let k = input.next().unwrap().parse::<i32>().unwrap();
                    Query::Put(i, k)
                }
                _ => panic!(),
            }
        })
        .collect::<Vec<_>>();

    let ans = Problem::new(n, vals, q, queries).solve();

    writeln!(stdout, "{}", ans).ok();
}
