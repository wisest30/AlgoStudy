impl Solution {
    pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
        let n = s.len();
        let mut delta = vec![0i32; n];
        for shift in shifts {
            let d = if shift[2] == 0 { -1 } else { 1 };
            delta[shift[0] as usize] += d;
            if shift[1] as usize + 1 < n {
                delta[shift[1] as usize + 1] -= d;
            }
        }

        let mut f = vec![0i32; n];
        f[0] = delta[0];
        for i in 1..n {
            f[i] = f[i - 1] + delta[i];
        }

        let shift_func = |c: char, i: i32| {
            let i = if i < 0 { i % 26 + 26 } else { i % 26 } as u8;
            let c = (c as u8 - 'a' as u8) % 26;
            ((c + i) % 26 + 'a' as u8) as char
        };

        s.chars()
            .enumerate()
            .map(|(i, c)| shift_func(c, f[i]))
            .collect::<String>()
    }
}
