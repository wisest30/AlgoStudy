impl Solution {
    pub fn minimized_maximum(n: i32, quantities: Vec<i32>) -> i32 {
        let check = |m| {
            quantities
            .iter()
            .fold(0, |acc, x| acc + (x + m - 1) / m)
            <= n
        };
        
        let mut l = 0;
        let mut r = 100_000;
        while l + 1 < r {
            let m = (l + r) / 2;
            if check(m) {
                r = m;
            } else {
                l = m;
            }
        }
        
        r
    }
}
