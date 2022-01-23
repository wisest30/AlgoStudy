#![allow(dead_code)]

struct Solution;

impl Solution {
    pub fn divide_string(mut s: String, k: i32, fill: char) -> Vec<String> {
        let k = k as usize;
        let l = s.len();

        let add_cnt = if l % k > 0 { k - (l % k) } else { 0 };
        s += fill.to_string().as_str().repeat(add_cnt).as_str();

        s.as_bytes()
            .windows(k)
            .step_by(k)
            .map(|x| std::str::from_utf8(&x).unwrap())
            .map(|x| String::from(x))
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use crate::leetcode2138::Solution;

    #[test]
    fn typical_cases() -> Result<(), String> {
        let s = "abcdefghi".into();
        let k = 3;
        let fill = 'x';
        let expected = ["abc", "def", "ghi"]
            .iter()
            .map(|&x| String::from(x))
            .collect::<Vec<_>>();
        assert_eq!(expected, Solution::divide_string(s, k, fill));

        let s = "abcdefghij".into();
        let k = 3;
        let fill = 'x';
        let expected = ["abc", "def", "ghi", "jxx"]
            .iter()
            .map(|&x| String::from(x))
            .collect::<Vec<_>>();
        assert_eq!(expected, Solution::divide_string(s, k, fill));

        Ok(())
    }
}
