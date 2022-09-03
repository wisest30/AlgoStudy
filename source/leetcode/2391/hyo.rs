fn f(garbage: &Vec<String>, travel: &Vec<i32>, c: char) -> i32 {
    if let Some((last, _)) = garbage
        .iter()
        .enumerate()
        .filter(|(i, s)| s.contains(c))
        .last()
    {
        let mut ret = 0;
        for i in 0..=last {
            ret += garbage[i].chars().filter(|&x| x == c).count();
            if i != last {
                ret += travel[i] as usize;
            }
        }

        ret as i32
    } else {
        0
    }
}

impl Solution {
    pub fn garbage_collection(garbage: Vec<String>, travel: Vec<i32>) -> i32 {
        f(&garbage, &travel, 'M') + f(&garbage, &travel, 'P') + f(&garbage, &travel, 'G')
    }
}
