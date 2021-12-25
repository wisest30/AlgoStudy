#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn first_palindrome(words: Vec<String>) -> String {
        let found = words.iter().find(|&w| {
            let it = w.as_bytes().iter(); // for ascii-only string
            let itrev = it.clone().rev();
            let mut itzip = it
                .clone()
                .take(it.len())
                .zip(itrev.clone().take(itrev.len()));

            itzip.all(|x| x.0 == x.1)
        });

        match found {
            Some(s) => s.clone(),
            None => String::new(),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first_palindrome_typical() {
        let words = ["abc", "car", "ada", "racecar", "cool"]
            .iter()
            .map(|&x| x.into())
            .collect();
        assert_eq!("ada", Solution::first_palindrome(words));

        let words = ["notapalindrome", "racecar"]
            .iter()
            .map(|&x| x.into())
            .collect();
        assert_eq!("racecar", Solution::first_palindrome(words));

        let words = ["def", "ghi"].iter().map(|&x| x.into()).collect();
        assert_eq!("", Solution::first_palindrome(words));
    }
}
