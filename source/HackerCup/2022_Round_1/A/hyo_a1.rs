use std::io::Read;

fn is_rotate(a: &Vec<usize>, b: &Vec<usize>) -> bool {
    let mut j = 0;
    while b[j] != a[0] {
        j += 1;
    }

    for i in 0..a.len() {
        if a[i] != b[(j + i) % a.len()] {
            return false;
        }
    }

    true
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let k = input.next().unwrap().parse::<usize>().unwrap();

        let a = (0..n)
            .map(|_| input.next().unwrap().parse::<usize>().unwrap())
            .collect::<Vec<_>>();

        let b = (0..n)
            .map(|_| input.next().unwrap().parse::<usize>().unwrap())
            .collect::<Vec<_>>();

        let rotate = is_rotate(&a, &b);
        let ans = if k == 0 {
            a == b
        } else if k == 1 {
            if a == b {
                false
            } else {
                rotate
            }
        } else if n == 2 {
            if k % 2 == 0 {
                a == b
            } else {
                a != b
            }
        } else {
            rotate
        };

        let ans = if ans { "YES" } else { "NO" };
        println!("Case #{tc}: {ans}");
    }
}
