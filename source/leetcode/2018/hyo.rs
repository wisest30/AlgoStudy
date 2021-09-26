fn is_possible(board: &Vec<Vec<char>>, word: &String, y: usize, x: usize, hori: bool) -> bool {
    let r = board.len();
    let c = board[0].len();
    let n = word.len();
    if hori {
        if x > 0 && board[y][x-1] != '#' {
            false
        } else if x + n < c && board[y][x+n] != '#' {
            false
        } else {
            for d in 0..=1 {
                let mut success = true;
                for (i, c) in word.chars().enumerate() {
                    let xx = if d == 0 { x + i } else { x + n - 1 - i};
                    if board[y][xx] != ' ' && board[y][xx] != c {
                        success = false;
                        break;
                    }
                }
                
                if success {
                    return true;
                }
            }
            
            false
        }
    } else {
        if y > 0 && board[y-1][x] != '#' {
            false
        } else if y + n < r && board[y+n][x] != '#' {
            false
        } else {
            for d in 0..=1 {
                let mut success = true;
                for (i, c) in word.chars().enumerate() {
                    let yy = if d == 0 { y + i } else { y + n - 1 - i};
                    if board[yy][x] != ' ' && board[yy][x] != c {
                        success = false;
                        break;
                    }
                }
                
                if success {
                    return true;
                }
            }
            
            false
        }        
    }
}

impl Solution {
    pub fn place_word_in_crossword(board: Vec<Vec<char>>, word: String) -> bool {
        let r = board.len();
        let c = board[0].len();
        let n = word.len();
        let mut v_cnt = vec![vec![0; c]; r];
        let mut h_cnt = vec![vec![0; c]; r];
        for y in 0..r {
            for x in 0..c {
                if board[y][x] == '#' {
                    v_cnt[y][x] = 1;
                    h_cnt[y][x] = 1;
                }
                
                if y > 0 {
                    v_cnt[y][x] += v_cnt[y-1][x];
                }
                if x > 0 {
                    h_cnt[y][x] += h_cnt[y][x-1];
                }
            }
        }
        
        let mut ret = false;
        if c >= n {
            for y in 0..r {
                for x in 0..=c-n {
                    if h_cnt[y][x+n-1] == if x > 0 {h_cnt[y][x-1]} else {0} {
                        ret |= is_possible(&board, &word, y, x, true);
                    }
                }
            }
        }
        
        if r >= n {
            for y in 0..=r-n {
                for x in 0..c {
                    if v_cnt[y+n-1][x] == if y > 0 {v_cnt[y-1][x]} else {0} {
                        ret |= is_possible(&board, &word, y, x, false);
                    }
                }
            }
        }
        
        ret
    }
}
