// O(n) solution, using queue
use std::collections::VecDeque;
use std::cmp::max;
impl Solution {
    pub fn count_vowel_substrings(word: String) -> i32 {
        let word: Vec<char> = word.chars().collect::<_>();
        let n = word.len();
        let mut idxs = vec![VecDeque::<usize>::new(); 6];
        
        let alpha_to_i = |c|
            if c == 'a' {0}
            else if c == 'e' {1}
            else if c == 'i' {2}
            else if c == 'o' {3}
            else if c == 'u' {4}
            else {5};
        
        word.iter().enumerate().for_each(|(i, &c)| idxs[alpha_to_i(c)].push_back(i));
        let mut ret = 0;
        for left in 0..n {
            if (0..5).any(|i| idxs[i].is_empty()) {
                break;
            }
            
            let min_right: usize = (0..5).fold(0, |acc, x| max(acc, *idxs[x].front().unwrap()));
            let consonant_idx = *idxs[5].front().unwrap_or(&n);
            if min_right <= consonant_idx {
                ret += consonant_idx - min_right;
            }
            
            idxs[alpha_to_i(word[left])].pop_front();
        }
        
        ret as i32
    }
}
