#[derive(Debug)]
struct DisjointSet {
    n: usize,
    g: Vec<usize>,
}

impl DisjointSet {
    pub fn new(sz: usize) -> Self {
        Self {
            n: sz,
            g: (0..sz).collect(),
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
        self.g[gy] = gx;
    }
}

impl Solution {
    pub fn friend_requests(n: i32, restrictions: Vec<Vec<i32>>, requests: Vec<Vec<i32>>) -> Vec<bool> {
        let n = n as usize;
        let restrictions: Vec<(usize, usize)>
            = restrictions.iter().map(|x| (x[0] as usize, x[1] as usize)).collect();
        let requests: Vec<(usize, usize)>
            = requests.iter().map(|x| (x[0] as usize, x[1] as usize)).collect();
        
        let mut ret: Vec<bool> = Vec::new();
        let mut ds = DisjointSet::new(n);
        for req in requests {
            let g0 = ds.find(req.0);
            let g1 = ds.find(req.1);
            let ans = restrictions.iter().all(
                |x| !(g0 == ds.find(x.0) && g1 == ds.find(x.1))
                    && !(g0 == ds.find(x.1) && g1 == ds.find(x.0))
            );
            
            if ans {
                ds.merge(req.0, req.1);
            }
            
            ret.push(ans);
        }
        
        ret
    }
}
