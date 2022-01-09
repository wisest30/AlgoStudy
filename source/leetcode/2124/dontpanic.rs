#![allow(unused)]

// FSA (or FSM) - automata written with match
struct Solution {}

impl Solution {
    pub fn check_string(s: String) -> bool {
        is_word_valid(&s)
    }

    // pub fn check_string_regex(s: String) -> bool {
    //     use lazy_static::lazy_static;
    //     use regex::Regex;
    //     lazy_static! {
    //         static ref  RE: Regex = Regex::new(r"a*b+").unwrap();
    //     }

    //     RE.is_match(&s)
    // }

    // // unsafe but effective solution by Hyoseong Park
    // pub fn check_string(s: String) -> bool {
    //     !s.contains("ba")
    // }
}

fn is_word_valid(s: &str) -> bool {
    let final_state = s
        .chars()
        .fold(State::Start, |state, c| state.do_transition(c));
    match final_state {
        State::Start | State::As | State::Bs => true,
        _ => false,
    }
}

enum State {
    Start,
    As,
    Bs,
    Failed,
}

impl State {
    fn do_transition(&self, c: char) -> State {
        match self {
            State::Start => match c {
                'a' => State::As,
                'b' => State::Bs,
                _ => State::Failed,
            },
            State::As => match c {
                'a' => State::As,
                'b' => State::Bs,
                _ => State::Failed,
            },
            State::Bs => match c {
                'b' => State::Bs,
                _ => State::Failed,
            },
            _ => State::Failed,
        }
    }
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        assert_eq!(true, Solution::check_string(String::from("aaabbb")));
        assert_eq!(false, Solution::check_string(String::from("abab")));
        assert_eq!(true, Solution::check_string(String::from("aaa")));
        assert_eq!(true, Solution::check_string(String::from("bbb")));
    }
}
