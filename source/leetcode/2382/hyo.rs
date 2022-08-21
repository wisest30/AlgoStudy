struct DisjointSet {
    g: Vec<usize>,
    sum: Vec<i64>,
    max_sum: i64,
}

impl DisjointSet {
    fn new(n: usize) -> Self {
        Self {
            g: (0..n).collect::<Vec<usize>>(),
            sum: vec![0; n],
            max_sum: 0,
        }
    }

    fn get_group(&mut self, x: usize) -> usize {
        if self.g[x] == x {
            x
        } else {
            self.g[x] = self.get_group(self.g[x]);
            self.g[x]
        }
    }

    fn merge(&mut self, x: usize, y: usize) {
        let gx = self.get_group(x);
        let gy = self.get_group(y);

        if gx != gy {
            self.g[gx] = gy;
            self.sum[gy] += self.sum[gx];
        }

        self.adjust_max_sum(self.sum[gy]);
    }

    fn adjust_max_sum(&mut self, new_val: i64) {
        self.max_sum = std::cmp::max(self.max_sum, new_val);
    }

    fn insert(&mut self, x: usize, val: i64) {
        let gx = self.get_group(x);
        self.sum[gx] += val;

        self.adjust_max_sum(self.sum[gx]);
    }

    fn get_max_sum(&self) -> i64 {
        self.max_sum
    }
}

impl Solution {
    pub fn maximum_segment_sum(nums: Vec<i32>, remove_queries: Vec<i32>) -> Vec<i64> {
        let n = nums.len();
        let mut ds = DisjointSet::new(n);
        let mut inserted = vec![false; n];
        let mut ret = vec![0i64; n];

        for i in (1..n).rev() {
            let x = remove_queries[i] as usize;
            ds.insert(x, nums[x] as i64);

            if x > 0 && inserted[x - 1] {
                ds.merge(x, x - 1);
            }
            if x + 1 < n && inserted[x + 1] {
                ds.merge(x, x + 1);
            }

            inserted[x] = true;
            ret[i - 1] = ds.get_max_sum();
        }

        ret
    }
}
