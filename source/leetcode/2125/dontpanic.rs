#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let it = bank
            .iter()
            .map(|s| s.as_bytes().iter().filter(|&&x| x == b'1').count())
            .filter(|&x| x > 0);
        let it2 = it.clone().skip(1);
        let itzip = it.zip(it2);

        itzip.fold(0, |acc, (x, y)| acc + x * y) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let bank = ["011001", "000000", "010100", "001000"]
            .iter()
            .map(|&x| String::from(x))
            .collect();
        assert_eq!(8, Solution::number_of_beams(bank));

        let bank = ["000", "111", "000"]
            .iter()
            .map(|&x| String::from(x))
            .collect();
        assert_eq!(0, Solution::number_of_beams(bank));
    }
}
