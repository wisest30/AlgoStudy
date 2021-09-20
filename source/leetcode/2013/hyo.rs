struct DetectSquares {
    cnt: Vec<Vec<i32>>,
    points: Vec<(i32, i32)>,
}

impl DetectSquares {

    fn new() -> Self {
        DetectSquares {
            cnt: vec![vec![0; 1001]; 1001],
            points: Vec::new(),
        }
    }
    
    fn add(&mut self, point: Vec<i32>) {
        self.cnt[point[0] as usize][point[1] as usize] += 1;
        self.points.push((point[0], point[1]));
    }
    
    fn count(&self, point: Vec<i32>) -> i32 {
        let x = point[0];
        let y = point[1];
        let mut ret = 0;
        for p in &self.points {
            let len_x = (x - p.0).abs();
            let len_y = (y - p.1).abs();
            if len_x > 0 && len_x == len_y {
                ret += self.cnt[x as usize][p.1 as usize]
                     * self.cnt[p.0 as usize][y as usize];
            }
        }
        
        ret
    }
}
