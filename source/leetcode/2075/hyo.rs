impl Solution {
    pub fn decode_ciphertext(encoded_text: String, rows: i32) -> String {
        let rows = rows as usize;
        let cols = encoded_text.len() / rows;
        let A = encoded_text.chars().collect::<Vec<_>>();

        let mut ret = String::new();
        for i in 0..cols {
            for j in 0..rows {
                match A.get(i + (cols + 1) * j) {
                    Some(c) => ret.push(*c),
                    _ => break
                }
            }
        }
        
        String::from(ret.trim_end())
    }
}
