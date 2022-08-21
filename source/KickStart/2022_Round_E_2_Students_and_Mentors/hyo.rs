use std::io::Read;

fn lower_bound(vec: &Vec<i32>, val: i32) -> usize {
    let mut l = 0;
    let mut r = vec.len();

    while l + 1 < r {
        let m = (l + r) / 2;
        if vec[m] >= val {
            r = m;
        } else {
            l = m;
        }
    }

    r
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let test_case_count = input.next().unwrap().parse::<usize>().unwrap();
    for test_case in 1..=test_case_count {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let ratings = (0..n)
            .map(|_| input.next().unwrap().parse::<i32>().unwrap())
            .collect::<Vec<_>>();

        let mut sorted = ratings.clone();
        sorted.sort_unstable();

        let iter = ratings.into_iter().map(|rating| {
            let i = lower_bound(&sorted, rating * 2 + 1);
            if i == 0 || sorted[i - 1] == rating && i == 1 {
                -1
            } else if sorted[i - 1] == rating {
                sorted[i - 2]
            } else {
                sorted[i - 1]
            }
        });

        let ans = iter
            .map(|rating| rating.to_string() + " ")
            .collect::<String>();

        println!("Case #{}: {}", test_case, ans);
    }
}
