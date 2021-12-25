#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let sb = s.as_bytes();
        let mut ans = Vec::<u8>::with_capacity(sb.len() + spaces.len());

        let mut indexes = Vec::<i32>::with_capacity(spaces.len() + 2);
        indexes.push(0);
        indexes.extend_from_slice(spaces.as_slice());
        indexes.push(sb.len() as i32);

        let it_intervals = indexes.as_slice().windows(2);

        let mut is_first_interval = true;
        for idx in it_intervals {
            let a = idx[0] as usize;
            let b = idx[1] as usize;

            if is_first_interval {
                is_first_interval = false;
            } else {
                ans.push(b' ');
            }
            ans.extend_from_slice(&sb[a..b]);
        }

        String::from_utf8(ans).unwrap_or_default()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn add_spaces_typical() {
        let s = String::from("LeetcodeHelpsMeLearn");
        let spaces = vec![8,13,15];
        assert_eq!(String::from("Leetcode Helps Me Learn"), Solution::add_spaces(s, spaces));

        let s = String::from("icodeinpython");
        let spaces = vec![1,5,7,9];
        assert_eq!(String::from("i code in py thon"), Solution::add_spaces(s, spaces));

        let s = String::from("spacing");
        let spaces = vec![0,1,2,3,4,5,6];
        assert_eq!(String::from(" s p a c i n g"), Solution::add_spaces(s, spaces));

    }
}
