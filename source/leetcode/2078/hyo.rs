impl Solution {
    pub fn max_distance(colors: Vec<i32>) -> i32 {
        (0..colors.len())
        .map(|i| (0..colors.len())
                .filter(|&j| colors[i] != colors[j])
                .last()
                .unwrap() as i32
                - i as i32)
        .max()
        .unwrap()
    }
}
