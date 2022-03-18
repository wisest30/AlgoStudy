impl Solution {
    pub fn dig_artifacts(n: i32, artifacts: Vec<Vec<i32>>, dig: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut A = vec![vec![false; n]; n];
        for d in dig {
            A[d[0] as usize][d[1] as usize] = true;
        }
        
        let valid = |rect: Vec<i32>| {
            for y in rect[0]..=rect[2] {
                for x in rect[1]..=rect[3] {
                    if !A[y as usize][x as usize] {
                        return false;
                    }
                }
            }
            
            true
        };
        
        artifacts
        .into_iter()
        .filter(|rect| valid(rect.to_vec()))
        .count() as i32
    }
}
