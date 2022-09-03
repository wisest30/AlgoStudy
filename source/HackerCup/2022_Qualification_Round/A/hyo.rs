use std::collections::HashMap;
use std::io::Read;

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let k = input.next().unwrap().parse::<usize>().unwrap();
        let styles = (0..n)
            .map(|_| input.next().unwrap().parse::<usize>().unwrap())
            .collect::<Vec<_>>();

        let ans = if 2 * k < n {
            false
        } else {
            let mut map = HashMap::new();
            let mut ans = true;
            for val in styles {
                let entry = map.entry(val).or_insert(0);
                if *entry >= 2 {
                    ans = false;
                    break;
                } else {
                    *entry += 1;
                }
            }

            ans
        };

        println!("Case #{tc}: {}", if ans { "YES" } else { "NO" });
    }
}
