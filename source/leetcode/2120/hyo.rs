impl Solution {
    pub fn execute_instructions(n: i32, start_pos: Vec<i32>, s: String) -> Vec<i32> {
        let s = s.chars().collect::<Vec<_>>();
        let m = s.len();
        (0..m).map(|i| {
            let mut y = start_pos[0];
            let mut x = start_pos[1];
            let mut ret = 0;
            for j in i..m {
                match s[j] {
                    'R' => x += 1,
                    'L' => x -= 1,
                    'U' => y -= 1,
                    'D' => y += 1,
                    _ => panic!(),
                }
                
                if x < 0 || x >= n || y < 0 || y >= n {
                    break;
                }
                ret += 1;
            }
            ret
        }).collect::<Vec<_>>()
    }
}
