use std::io::{Read, Write};

const INVALID_INDEX: usize = std::usize::MAX;
struct Problem {
    m: usize,
    min_index_for_sum: Vec<Vec<usize>>,
}

impl Problem {
    fn new(n: usize, m: usize, v: Vec<i32>) -> Self {
        let min_index_for_sum = Self::min_index_for_sum(n, m, &v);
        Self {
            m,
            min_index_for_sum,
        }
    }

    fn min_index_for_sum(n: usize, m: usize, v: &Vec<i32>) -> Vec<Vec<usize>> {
        let mut ret = (0..n + 1)
            .map(|i| {
                let mut res = vec![INVALID_INDEX; m];
                let mut cur_sum = 0;
                res[0] = i;
                for j in i..n {
                    cur_sum = (cur_sum + v[j]) % m as i32;
                    if res[cur_sum as usize] == INVALID_INDEX {
                        res[cur_sum as usize] = j + 1;
                    }
                }
                res
            })
            .collect::<Vec<_>>();

        for i in (0..n).rev() {
            for j in 0..m {
                if ret[i][j] == INVALID_INDEX {
                    ret[i][j] = ret[i + 1][j];
                }
            }
        }

        ret
    }

    fn solve(&mut self) -> usize {
        // 8192
        let node_cnt = 1 << 13;
        let mut dist = vec![INVALID_INDEX; node_cnt];
        // (-min_index, xor hash)
        let mut heap = std::collections::BinaryHeap::new();
        heap.push((0, 0));

        while !heap.is_empty() {
            let (neg_min_index, xor_hash) = heap.pop().unwrap();
            let min_index = (-neg_min_index) as usize;
            if min_index >= dist[xor_hash] {
                continue;
            }
            dist[xor_hash] = min_index;
            for nxt_xor_hash in 1..node_cnt {
                let sum = nxt_xor_hash ^ xor_hash;
                if sum >= self.m {
                    continue;
                }
                let nxt_min_index = self.min_index_for_sum[min_index][sum];
                if nxt_min_index == INVALID_INDEX {
                    continue;
                }
                heap.push((-(nxt_min_index as i32), nxt_xor_hash));
            }
        }

        dist.into_iter()
            .filter(|&min_index| min_index != INVALID_INDEX)
            .count()
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();
        let v: Vec<i32> = (0..n)
            .map(|_| input.next().unwrap().parse::<i32>().unwrap())
            .collect();
        let ans = Problem::new(n, m, v).solve();

        writeln!(stdout, "Case #{tc}: {}", ans).ok();
    }
}
