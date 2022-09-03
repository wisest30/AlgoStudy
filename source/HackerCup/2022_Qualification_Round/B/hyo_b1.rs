use std::io::Read;

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let r = input.next().unwrap().parse::<usize>().unwrap();
        let c = input.next().unwrap().parse::<usize>().unwrap();

        let mut is_empty_scene = true;
        (0..r).for_each(|_| {
            if let Some(_) = input.next().unwrap().find('^') {
                is_empty_scene = false;
            }
        });

        if (r == 1 || c == 1) && !is_empty_scene {
            println!("Case #{tc}: Impossible");
        } else {
            println!("Case #{tc}: Possible");
            let s = if is_empty_scene { "." } else { "^" };
            (0..r).for_each(|_| println!("{}", s.repeat(c)));
        }
    }
}

