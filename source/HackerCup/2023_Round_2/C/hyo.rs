use std::{
    collections::{HashMap, HashSet},
    io::{Read, Write},
};

const INVALID_INDEX: usize = 123456789;
struct Problem {
    n: usize,
    p: Vec<usize>,
    s: Vec<HashSet<String>>,
    g: Vec<Vec<usize>>,
}

#[derive(Clone, Copy, PartialEq, Eq, Debug)]
enum DfsRes {
    Valid,
    PartialValid,
    Invalid,
}

impl Problem {
    fn new(n: usize, p: Vec<usize>, s: Vec<HashSet<String>>) -> Self {
        Self {
            n,
            p,
            s,
            g: Vec::new(),
        }
    }

    fn solve(&mut self) -> usize {
        self.init();
        self.pruning_words();
        self.dfs_merge();

        let words = self
            .s
            .iter()
            .flat_map(|set| set.iter())
            .collect::<HashSet<_>>();
        words.iter().filter(|word| self.is_valid_word(word)).count()
    }

    fn init(&mut self) {
        self.g = vec![Vec::new(); self.n];
        for i in 0..self.n {
            if self.p[i] != INVALID_INDEX {
                self.g[self.p[i]].push(i);
            }
        }
    }

    fn pruning_words(&mut self) {
        let leaf_cnt = self.count_leaf_node();

        let mut map = HashMap::new();
        self.s.iter().flat_map(|set| set.iter()).for_each(|word| {
            *map.entry(word.clone()).or_insert(0) += 1;
        });

        self.s.iter_mut().for_each(|set| {
            set.retain(|word| map[word] >= leaf_cnt);
        });
    }

    fn count_leaf_node(&self) -> usize {
        self.g.iter().filter(|v| v.is_empty()).count()
    }

    fn dfs_merge(&mut self) {
        let mut stack = vec![0];
        while !stack.is_empty() {
            let cur = stack.pop().unwrap();
            if self.g[cur].len() == 1 {
                let nxt = self.g[cur][0];

                let edges = std::mem::take(&mut self.g[nxt]);
                self.g[cur] = edges;

                let set = std::mem::take(&mut self.s[nxt]);
                self.s[cur].extend(set);

                stack.push(cur);
            } else {
                for nxt in self.g[cur].clone() {
                    stack.push(nxt);
                }
            }
        }
    }

    fn is_valid_word(&self, word: &str) -> bool {
        let mut visited = vec![false; self.n];
        let mut st = vec![0];
        let mut ret = vec![DfsRes::Valid; self.n];
        while !st.is_empty() {
            let cur = *st.last().unwrap();

            if !visited[cur] {
                visited[cur] = true;
                self.g[cur].iter().for_each(|&nxt| st.push(nxt));
                continue;
            }

            st.pop();

            let mut valid = 0;
            let mut partial_valid = 0;
            let mut invalid = 0;
            for &nxt in &self.g[cur] {
                match ret[nxt] {
                    DfsRes::Valid => valid += 1,
                    DfsRes::PartialValid => partial_valid += 1,
                    DfsRes::Invalid => invalid += 1,
                }
            }

            let cur_contains = self.s[cur].contains(word);
            ret[cur] = if invalid > 0 || partial_valid > 1 {
                DfsRes::Invalid
            } else if partial_valid == 1 {
                if cur_contains {
                    DfsRes::Valid
                } else {
                    DfsRes::PartialValid
                }
            } else if valid == 0 && !cur_contains {
                DfsRes::PartialValid
            } else {
                DfsRes::Valid
            }
        }

        ret[0] == DfsRes::Valid
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

        let mut p = vec![INVALID_INDEX];
        p.extend((0..n - 1).map(|_| input.next().unwrap().parse::<usize>().unwrap() - 1));

        let s = (0..n)
            .map(|_| {
                let m = input.next().unwrap().parse::<usize>().unwrap();
                (0..m)
                    .map(|_| input.next().unwrap().to_string())
                    .collect::<HashSet<_>>()
            })
            .collect::<Vec<_>>();

        let mut prob = Problem::new(n, p, s);
        let ans = prob.solve();

        writeln!(stdout, "Case #{tc}: {}", ans).ok();
    }
}
