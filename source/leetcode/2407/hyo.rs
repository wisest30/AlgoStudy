type T = i32;
struct MaxSegTree {
    n: usize,
    val: Vec<T>,
}

impl MaxSegTree {
    pub fn new(n: usize) -> Self {
        MaxSegTree {
            n,
            val: vec![0; 4 * n + 10],
        }
    }

    fn set_(&mut self, i: usize, l: usize, r: usize, pos: usize, x: T) {
        if l + 1 == r {
            self.val[i] = x;
        } else {
            let m = (l + r) / 2;
            if pos < m {
                self.set_(i * 2 + 1, l, m, pos, x);
            } else {
                self.set_(i * 2 + 2, m, r, pos, x);
            }
            self.val[i] = std::cmp::max(self.val[i * 2 + 1], self.val[i * 2 + 2]);
        }
    }

    pub fn set(&mut self, pos: usize, x: T) {
        self.set_(0, 0, self.n, pos, x);
    }

    fn get_(&self, i: usize, l: usize, r: usize, left: usize, right: usize) -> T {
        if left <= l && r <= right {
            self.val[i]
        } else {
            let m = (l + r) / 2;

            if right <= m {
                self.get_(i * 2 + 1, l, m, left, right)
            } else if m <= left {
                self.get_(i * 2 + 2, m, r, left, right)
            } else {
                std::cmp::max(
                    self.get_(i * 2 + 1, l, m, left, right),
                    self.get_(i * 2 + 2, m, r, left, right),
                )
            }
        }
    }

    pub fn get(&self, left: usize, right: usize) -> T {
        self.get_(0, 0, self.n, left, right)
    }
}

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>, k: i32) -> i32 {
        const TREE_SZ: usize = 100001;
        let mut t = MaxSegTree::new(100001);
        for num in nums {
            let left = std::cmp::max(0, num - k) as usize;
            let right = num as usize;
            let x = t.get(left, right) + 1;
            t.set(num as usize, x);
        }

        t.get(0, TREE_SZ)
    }
}
