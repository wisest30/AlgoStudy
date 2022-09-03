use std::io::Read;

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();

    let mut dot_starts = Vec::<String>::new();
    let mut dash_starts = Vec::<String>::new();
    for x in 0..1 << 10 {
        let mut s = String::new();
        for i in 0..10 {
            s.push(if (x & (1 << i)) == 0 { '.' } else { '-' });
        }

        if (x & 1) == 0 {
            dot_starts.push(s);
        } else {
            dash_starts.push(s);
        }
    }

    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let c1 = input.next().unwrap();

        let codewords = if c1.starts_with('.') {
            &dash_starts
        } else {
            &dot_starts
        };

        println!("Case #{tc}: ");
        for s in codewords.iter().take(n - 1) {
            println!("{}", s);
        }
    }
}

