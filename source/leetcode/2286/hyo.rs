struct SegTree {
    n: usize,
    T: Vec<usize>,
    S: Vec<i64>,
}

impl SegTree {
    fn new(n: usize, m: usize) -> Self {
        SegTree { n, T : vec![0; n * 4 + 10], S : vec![0; n * 4 + 10] }
    }
    
    fn set(&mut self, i: usize, l: usize, r: usize, idx: usize, val: usize) {
        if l + 1 == r {
            self.T[i] = val;
            self.S[i] = val as i64;
        } else {
            let m = (l + r) / 2;
            if idx < m {
                self.set(i * 2 + 1, l, m, idx, val);
            } else {
                self.set(i * 2 + 2, m, r, idx, val);
            }
            self.T[i] = std::cmp::max(self.T[i * 2 + 1], self.T[i * 2 + 2]);
            self.S[i] = self.S[i * 2 + 1] + self.S[i * 2 + 2];
        }
    }
    
    fn get(&self, i: usize, l: usize, r: usize, idx: usize) -> usize {
        if l + 1 == r {
            self.T[i]
        } else {
            let m = (l + r) / 2;
            if idx < m {
                self.get(i * 2 + 1, l, m, idx)
            } else {
                self.get(i * 2 + 2, m, r, idx)
            }
        }
    }
    
    fn search(&self, i: usize, l: usize, r: usize, k: usize) -> usize {
        if self.T[i] < k {
            self.n
        } else if l + 1 == r {
            l
        } else if self.T[i * 2 + 1] >= k {
            self.search(i * 2 + 1, l, (l + r) / 2, k)
        } else {
            self.search(i * 2 + 2, (l + r) / 2, r, k)
        }
    }
    
    fn get_sum(&self, i: usize, l: usize, r: usize, max_r: usize) -> i64 {
        if l >= max_r {
            0
        } else if r <= max_r {
            self.S[i]
        } else {
            let m = (l + r) / 2;
            if max_r <= m {
                self.get_sum(i * 2 + 1, l, m, max_r)
            } else {
                self.S[i * 2 + 1] + self.get_sum(i * 2 + 2, m, r, max_r)
            }
        }
    }
}

struct BookMyShow {
    n: usize,
    m: usize,
    tree: SegTree,
}

impl BookMyShow {

    fn new(n: i32, m: i32) -> Self {
        let n = n as usize;
        let m = m as usize;
        let mut tree = SegTree::new(n as usize, m as usize);
        for i in 0..n {
            tree.set(0, 0, n, i, m);
        }
        BookMyShow{n, m, tree }
    }
    
    fn gather(&mut self, k: i32, max_row: i32) -> Vec<i32> {
        let k = k as usize;
        let max_row = max_row as usize;
        let i = self.tree.search(0, 0, self.n, k);
        if i > max_row {
            vec![]
        } else {
            let capacity = self.tree.get(0, 0, self.n, i);
            self.tree.set(0, 0, self.n, i, capacity - k);
            vec![i as i32, (self.m - capacity) as i32]
        }
    }
    
    fn scatter(&mut self, k: i32, max_row: i32) -> bool {
        let mut k = k as usize;
        let max_row = max_row as usize;
        if self.tree.get_sum(0, 0, self.n, max_row + 1) < k as i64 {
            false
        } else {
            while k > 0 {
                let i = self.tree.search(0, 0, self.n, 1);
                let val = self.tree.get(0, 0, self.n, i);
                if val <= k {
                    self.tree.set(0, 0, self.n, i, 0);
                    k -= val;
                } else {
                    self.tree.set(0, 0, self.n, i, val - k);
                    k = 0;
                }
            }
            true
        }
    }
}
