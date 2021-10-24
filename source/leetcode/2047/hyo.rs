impl Solution {
    fn check(s: &str) -> bool {
        let v = s.chars().collect::<Vec<_>>();
        let mut h = false;
        let mut p = false;
        for (i, &c) in v.iter().enumerate() {
            if c.is_digit(10) {
                return false;
            } else if(c == '-') {
                if h || i == 0 || i+1 == v.len() || !v[i-1].is_alphabetic() || !v[i+1].is_alphabetic() {
                    return false;
                } else {
                    h = true;
                }
            } else if(c == '.' || c == '!' || c == ',') {
                if p || i != v.len() - 1 {
                    return false;
                } else {
                    p = true;
                }
            }
        }
        
        true
    }
    
    pub fn count_valid_words(sentence: String) -> i32 {       
        sentence.split_whitespace().filter(|x| Solution::check(x)).count() as i32
    }
}
