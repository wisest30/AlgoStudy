use std::collections::HashMap;

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {a} else {gcd(b, a % b)}
}

impl Solution {
    pub fn interchangeable_rectangles(rectangles: Vec<Vec<i32>>) -> i64 {
        let mut map = HashMap::new();
        let mut ret:i64 = 0;
        for rect in rectangles {
            let p: f64 = (rect[0] as f64) / (rect[1] as f64);
            let g = gcd(rect[0], rect[1]);
            let key = (rect[0] / g, rect[1] / g);
            
            let v = map.entry(key).or_insert(0);
            
            ret += *v as i64;
            *v += 1;
        }
                
        ret
    }
}
