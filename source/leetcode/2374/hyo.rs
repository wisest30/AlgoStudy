impl Solution {
    pub fn edge_score(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut scores = vec![0; n];
        for i in 0..n {
            scores[edges[i] as usize] += i;
        }

        let mut ret = 0;
        let mut max_score = 0;
        for i in 0..n {
            if scores[i] > max_score {
                ret = i;
                max_score = scores[i];
            }
        }

        ret as i32
    }
}
