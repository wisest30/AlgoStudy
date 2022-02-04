use std::collections::HashMap;

struct DisjointSet {
    g : Vec<usize>,
    cnts : Vec<usize>,
    max_cnt : usize,
    group_cnt : usize,
}

impl DisjointSet {
    pub fn new(n: usize) -> DisjointSet {
        DisjointSet{
            g : (0..n).collect::<Vec<usize>>(),
            cnts : vec![1; n],
            max_cnt : 1,
            group_cnt : n,
        }
    }
    
    pub fn find(&mut self, x: usize) -> usize {
        if self.g[x] == x {
            x
        } else {
            self.g[x] = self.find(self.g[x]);
            self.g[x]
        }
    }
    
    pub fn merge(&mut self, x: usize, y: usize) {
        let gx = self.find(x);
        let gy = self.find(y);
        if gx != gy {
            self.g[gy] = gx;
            self.cnts[gx] += self.cnts[gy];
            self.max_cnt = std::cmp::max(self.max_cnt, self.cnts[gx]);
            self.group_cnt -= 1;
        }
    }
    
    pub fn get_group_cnt(&self) -> usize {
        self.group_cnt
    }
    
    pub fn get_max_cnt(&self) -> usize {
        self.max_cnt
    }
}

impl Solution {
    pub fn group_strings(words: Vec<String>) -> Vec<i32> {
        fn str_to_bit(s : String) -> usize {
            s.chars().map(|c| 1usize << (c as u8 - 'a' as u8)).sum()
        }
        
        let n = words.len();
        let bits = words
                   .into_iter()
                   .map(|s| str_to_bit(s))
                   .collect::<Vec<_>>();
        
        let mut ds = DisjointSet::new(n);
        let mut map = HashMap::new();
        for (i, bit) in bits.into_iter().enumerate() {
            if let Some(&x) = map.get(&bit) {
                ds.merge(i, x);
            }
            
            for j in 0..26 {
                if let Some(&x) = map.get(&(bit ^ (1 << j))) {
                    ds.merge(i, x);
                }
            }

            for j in 0..26 {
                for k in j+1..26 {
                    if (((bit >> j) & 1) != ((bit >> k) & 1)) {
                        if let Some(&x) = map.get(&(bit ^ (1 << j) ^ (1 << k))) {
                            ds.merge(i, x);
                        }
                    }
                }
            }
            map.insert(bit, i);
        }
        
        vec![ds.get_group_cnt() as i32, ds.get_max_cnt() as i32]
    }
}
