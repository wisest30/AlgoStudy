impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let s = s.chars().collect::<Vec<_>>();
        let spaces: Vec<usize> = spaces.iter().map(|&x| x as usize).collect();
        let mut j = 0;
        let mut ret = Vec::new();
        for i in 0..s.len() {
            if j < spaces.len() && spaces[j] == i {
                ret.push(' ');
                j += 1;
            }
            
            ret.push(s[i]);
        }
        
        ret.iter().collect()
    }
}
