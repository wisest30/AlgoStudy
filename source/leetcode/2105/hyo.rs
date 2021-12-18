impl Solution {
    pub fn minimum_refill(plants: Vec<i32>, capacity_a: i32, capacity_b: i32) -> i32 {
        let n = plants.len();
        let mut a = capacity_a;
        let mut b = capacity_b;
        let mut i = 0;
        let mut j = n - 1;
        let mut ret = 0;
        
        while i <= j {
            if i == j {
                if a < plants[i] && b < plants[j] {
                    ret += 1;
                }
                break;
            } else {
                if a < plants[i] {
                    a = capacity_a;
                    ret += 1;
                }
                if b < plants[j] {
                    b = capacity_b;
                    ret += 1;
                }
                
                a -= plants[i];
                b -= plants[j];
                i += 1;
                j -= 1;
            }
        }
        
        ret
    }
}
