impl Solution {
    pub fn largest_word_count(messages: Vec<String>, senders: Vec<String>) -> String {
        let mut map = std::collections::HashMap::new();
        let mut ans = (0, "".to_string());
        for i in 0..messages.len() {
            let e = map.entry(&senders[i]).or_insert(0);
            *e += messages[i].split(' ').count();
            ans = std::cmp::max(ans, (*e, senders[i].clone()));
        }
        
        ans.1
    }
}
