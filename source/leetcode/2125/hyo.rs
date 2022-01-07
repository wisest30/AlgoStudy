impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut prev = 0;
        bank.iter()
            .filter(|s| s.contains("1"))
            .map(|s| s.chars().filter(|&c| c == '1').count())
            .fold(0, |acc, x| { 
                let ret = acc + x * prev;
                prev = x;
                ret
            }) as i32
    }
}
