impl Solution {
    pub fn decode_message(key: String, message: String) -> String {
        use std::collections::HashMap;

        let mut map = HashMap::new();
        let mut cur = b'a';
        for &c in key.as_bytes() {
            if c != b' ' && !map.contains_key(&c) && cur <= b'z' {
                map.insert(c, cur.clone());
                cur += 1;
            }
        }
        map.insert(b' ', b' ');

        message
            .chars()
            .map(|x| *map.get(&(x as u8)).unwrap() as char)
            .collect::<String>()
    }
}
