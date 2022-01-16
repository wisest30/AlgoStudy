impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        fn fill_chars(mut v: Vec<char>, k: usize, fill: char) -> Vec<char>{
            if v.len() % k > 0 { v.append(&mut vec![fill; k - v.len() % k]) }
            v
        }
        fn split_to_string(v: Vec<char>, k: usize) -> Vec<String>{
            (0..v.len()).step_by(k).map(|i| v[i..i+k].iter().collect::<String>()).collect::<_>()
        } 
        let mut v = s.chars().collect::<Vec<char>>();
        let k = k as usize;
        
        split_to_string(fill_chars(v, k, fill), k)
    }
}
