pub fn are_numbers_ascending(s: String) -> bool {
    // let numbers: Vec<_> = s
    //     .split_whitespace()
    //     .filter_map(|s| s.parse::<i32>().ok())
    //     .collect();
    // numbers.windows(2).all(|n| n[0] <= n[1])
                                              
    let it1 = s.split_whitespace().filter_map(|s| s.parse::<i32>().ok());
    let it2 = it1.clone().skip(1);

    it1.zip(it2).all(|(a, b)| a < b)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn are_numbers_ascending_typical() {
        let s = String::from("test 1 2 3");
        assert_eq!(true, are_numbers_ascending(s));

        let s = String::from("test 2 1 3");
        assert_eq!(false, are_numbers_ascending(s));

        let s = String::from("test 1 2 2 3");
        assert_eq!(false, are_numbers_ascending(s));
    }
}
