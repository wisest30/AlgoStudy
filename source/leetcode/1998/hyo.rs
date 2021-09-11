struct DisjointSet {
    G : Vec<usize>
}

impl DisjointSet {
    fn new(n : usize) -> DisjointSet {
        DisjointSet{
            G : (0..n).collect()
        }
    }
    
    fn find(&mut self, x : usize) -> usize {
        if self.G[x] == x {
            x
        } else {
            self.G[x] = self.find(self.G[x]);
            self.G[x]
        }
    }
    
    fn merge(&mut self, x : usize, y : usize) {
        let gx = self.find(x);
        let gy = self.find(y);
        self.G[gx] = gy;
    }
}

fn get_factors(x: i32) -> Vec<i32> {
    let mut y = 1;
    let mut F = vec![0; 0];
    while y * y <= x {
        if x % y == 0 {
            F.push(y);

            if x / y != y {
                F.push(x / y);
            }
        }

        y += 1;
    }

    F
}

impl Solution {
    pub fn gcd_sort(N: Vec<i32>) -> bool {
        let n = N.len();
        let mut ds = DisjointSet::new(n);
        let mut M: Vec<Option<usize>> = vec![None; 100001];
        
        for (i, &v) in N.iter().enumerate() {
            for x in get_factors(v) {
                if x != 1 && M[x as usize] != None {
                    ds.merge(i, M[x as usize].unwrap());
                }
                
                M[x as usize] = Some(i);
            }            
        }
        
        let mut A = vec![vec![0; 0]; n];
        for i in 0..n {
            let g = ds.find(i);
            A[g].push(N[i]);
        }
        
        for i in 0..n {
            A[i].sort();
        }
                
        let mut SN = vec![0; n];
        for i in (0..n).rev() {
            let g = ds.find(i);
            SN[i] = *A[g].last().unwrap();
            A[g].pop();
        }
        
        let mut ret = true;
        for i in 0..n-1 {
            if SN[i] > SN[i + 1] {
                ret = false;
                break;
            }
        }
                
        ret
    }
}
