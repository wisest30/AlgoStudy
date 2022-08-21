use std::io::Read;

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let test_case_count = input.next().unwrap().parse::<usize>().unwrap();
    for test_case in 1..=test_case_count {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let ans = (n + 4) / 5;
        println!("Case #{}: {}", test_case, ans);
    }
}
