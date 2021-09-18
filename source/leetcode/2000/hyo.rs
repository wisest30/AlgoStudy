impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        let p = word.find(ch);
        
        if p == None {
            word
        } else {
            let pre = (&word[..p.unwrap() + 1]).to_string();
            let suf = (&word[p.unwrap() + 1 ..]).to_string();
            let rev_pre : String = pre.chars().rev().collect();
            
            let ret = rev_pre + &suf;
            
            ret
        }
    }
}
