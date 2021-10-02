impl Solution {
    pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
        let m = m as usize;
        let n = n as usize;
        if m * n == original.len() {
            original.chunks(n as usize).map(|x| x.to_vec()).collect::<Vec<Vec<i32>>>()
        } else {
            vec![vec![0; 0]; 0]
        }
    }
}
