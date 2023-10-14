use std::io::{Read, Write};

const MOD: u64 = 100000000003u64;
const INVALID_HASH: u64 = MOD + 1;
const MAX_GROUP_SIZE: usize = 2000;
const INVALID_INDEX: usize = 123456789;
const BULK_SIZE: usize = 1000;

struct HashFactory {
    hashes: Vec<u64>,
}

impl HashFactory {
    pub fn new(s: String) -> Self {
        let hashes = s
            .chars()
            .rev()
            .scan(0, |acc, c| {
                *acc = (*acc * 31 + c as u64 - 'a' as u64 + 1) % MOD;
                Some(*acc)
            })
            .collect::<Vec<_>>()
            .into_iter()
            .rev()
            .collect::<Vec<_>>();

        Self { hashes }
    }

    pub fn get_hash(&self) -> u64 {
        if self.hashes.is_empty() {
            INVALID_HASH
        } else {
            *self.hashes.last().unwrap()
        }
    }

    pub fn pop_hash(&mut self, count: usize) -> u64 {
        for _ in 0..count {
            if self.hashes.is_empty() {
                return INVALID_HASH;
            } else {
                self.hashes.pop().unwrap();
            }
        }

        self.get_hash()
    }
}

struct HashGroupCounter {
    left_idx: usize,
    right_idx: usize,
    k: usize,
    hash_factories: Vec<HashFactory>,
    indexes: std::collections::BTreeSet<usize>,
    counts: Vec<usize>,
    group_size: std::collections::HashMap<u64, i64>,
}

impl HashGroupCounter {
    pub fn new(words: Vec<String>) -> Self {
        let hash_factories = words.into_iter().map(HashFactory::new).collect::<Vec<_>>();
        let indexes = (0..hash_factories.len()).collect::<std::collections::BTreeSet<_>>();

        Self {
            left_idx: INVALID_INDEX,
            right_idx: INVALID_INDEX,
            k: 1,
            hash_factories,
            indexes,
            counts: vec![0; MAX_GROUP_SIZE],
            group_size: std::collections::HashMap::new(),
        }
    }

    fn next_index(&self, idx: usize) -> usize {
        *self
            .indexes
            .range(idx + 1..)
            .next()
            .unwrap_or(&INVALID_INDEX)
    }

    pub fn query(&mut self, l: usize, r: usize, k: usize) -> usize {
        if self.indexes.is_empty() {
            return 0;
        }
        if self.k < k {
            self.inc_k(k - self.k);
        }

        let new_left_idx = if self.indexes.contains(&l) {
            l
        } else {
            self.next_index(l)
        };
        self.set_left_idx(new_left_idx);

        let new_right_idx = if self.indexes.contains(&r) {
            r
        } else {
            self.next_index(r)
        };
        self.set_right_idx(new_right_idx);

        self.answer()
    }

    fn inc_k(&mut self, count: usize) {
        let mut removes = Vec::new();
        self.indexes
            .iter()
            .copied()
            .collect::<Vec<_>>()
            .into_iter()
            .for_each(|idx| {
                let h = self.hash_factories[idx].pop_hash(count);
                if h == INVALID_HASH {
                    removes.push(idx);
                }
            });

        removes.iter().for_each(|&idx| {
            self.indexes.remove(&idx);
        });

        self.left_idx = INVALID_INDEX;
        self.right_idx = INVALID_INDEX;
        self.counts = vec![0; MAX_GROUP_SIZE];
        self.k += count;
    }

    fn set_left_idx(&mut self, new_left_idx: usize) {
        if self.left_idx < new_left_idx {
            self.indexes
                .range(self.left_idx..new_left_idx)
                .copied()
                .collect::<Vec<_>>()
                .into_iter()
                .for_each(|idx| self.remove_hash(idx));
        } else if self.left_idx > new_left_idx {
            self.indexes
                .range(new_left_idx..self.left_idx)
                .copied()
                .collect::<Vec<_>>()
                .into_iter()
                .for_each(|idx| {
                    self.add_hash(idx);
                });
        }

        self.left_idx = new_left_idx;
    }

    fn set_right_idx(&mut self, new_right_idx: usize) {
        if self.right_idx < new_right_idx {
            self.indexes
                .range(self.right_idx..new_right_idx)
                .copied()
                .collect::<Vec<_>>()
                .into_iter()
                .for_each(|idx| {
                    self.add_hash(idx);
                });
        } else if self.right_idx > new_right_idx {
            self.indexes
                .range(new_right_idx..self.right_idx)
                .copied()
                .collect::<Vec<_>>()
                .into_iter()
                .for_each(|idx| {
                    self.remove_hash(idx);
                });
        }

        self.right_idx = new_right_idx;
    }

    fn remove_group_size(&mut self, sz: i64) {
        if sz > 0 {
            self.counts[(sz as usize).min(MAX_GROUP_SIZE - 1)] -= 1;
        }
    }

    fn add_group_size(&mut self, sz: i64) {
        if sz > 0 {
            self.counts[(sz as usize).min(MAX_GROUP_SIZE - 1)] += 1;
        }
    }

    fn remove_hash(&mut self, idx: usize) {
        let h = self.hash_factories[idx].get_hash();
        self.remove_group_size(*self.group_size.get(&h).unwrap_or(&0));
        let sz = *self
            .group_size
            .entry(h)
            .and_modify(|e| *e -= 1)
            .or_insert(-1);
        self.add_group_size(sz);
    }

    fn add_hash(&mut self, idx: usize) {
        let h = self.hash_factories[idx].get_hash();
        self.remove_group_size(*self.group_size.get(&h).unwrap_or(&0));
        let sz = *self
            .group_size
            .entry(h)
            .and_modify(|e| *e += 1)
            .or_insert(1);
        self.add_group_size(sz);
    }

    fn answer(&self) -> usize {
        let mut ans = 0;
        let mut need_count = 1;
        for i in 1..self.counts.len() {
            let mut count = self.counts[i];
            while i >= need_count && count > 0 {
                ans += 1;
                need_count += 1;
                count -= 1;
            }
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

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let words = (0..n)
            .map(|_| input.next().unwrap().to_string())
            .collect::<Vec<_>>();
        let q = input.next().unwrap().parse::<usize>().unwrap();
        let mut queries = (0..q)
            .map(|_| {
                let l = input.next().unwrap().parse::<usize>().unwrap() - 1;
                let r = input.next().unwrap().parse::<usize>().unwrap();
                let k = input.next().unwrap().parse::<usize>().unwrap();
                (l, r, k)
            })
            .collect::<Vec<_>>();
        queries.sort_unstable_by_key(|&(l, r, k)| (k, l / BULK_SIZE, r));
        let mut counter = HashGroupCounter::new(words);

        let ans = queries
            .into_iter()
            .fold(0, |acc, (l, r, k)| acc + counter.query(l, r, k));

        writeln!(stdout, "Case #{tc}: {}", ans).ok();
    }
}
