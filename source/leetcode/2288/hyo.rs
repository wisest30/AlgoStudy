impl Solution {
    pub fn discount_prices(sentence: String, discount: i32) -> String {
        let mut words = sentence.split(' ').collect::<Vec<_>>();
        let mut ret = String::new();
        for word in words {
            let mut is_price = false;
            if word.len() <= 11 && word.len() > 1 {
                let letters = word.chars().collect::<Vec<char>>();
                if letters[0] == '$'
                    && letters.iter().filter(|&&c| c == '$' || c == '.' || c.is_alphabetic()).count() == 1
                {
                    is_price = true;
                }
            }
            
            let add = if is_price { 
                let price = (100 - discount) as f64 / 100.0 * word.chars().skip(1).collect::<String>().parse::<f64>().unwrap();
                format!("${:.2}", price)
            } else {
                word.to_string()
            };

            if !ret.is_empty() {
                ret.push(' ');
            }
            
            ret += &add;
        }
        
        ret
    }
}
