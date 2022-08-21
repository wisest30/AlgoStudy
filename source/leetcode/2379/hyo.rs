impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let blocks = blocks.chars().collect::<Vec<char>>();
        let k = k as usize;
        (0..=blocks.len() - k)
            .map(|i| blocks.iter().skip(i).take(k).filter(|&c| *c == 'W').count())
            .min()
            .unwrap() as i32
    }
}
