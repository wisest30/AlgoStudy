use std::io::{stdin, Read};

fn dfs(
    g: &Vec<Vec<usize>>,
    cur: usize,
    k: usize,
    visited: &mut Vec<bool>,
    mut visited_cnt: usize,
) -> usize {
    visited[cur] = true;
    visited_cnt += 1;

    for &nxt in g[cur].iter() {
        if visited_cnt > k {
            break;
        }

        if !visited[nxt] {
            visited_cnt = dfs(g, nxt, k, visited, visited_cnt);
        }
    }

    visited_cnt
}

fn main() {
    let mut stdin = stdin();
    let mut buf = String::new();
    stdin.read_to_string(&mut buf).ok();
    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();
        let k = input.next().unwrap().parse::<usize>().unwrap();

        let mut g = vec![vec![0usize; 0]; n];
        for _ in 0..m {
            let u = input.next().unwrap().parse::<usize>().unwrap() - 1;
            let v = input.next().unwrap().parse::<usize>().unwrap() - 1;

            g[v].push(u);
        }

        let ans = (0..n)
            .filter(|&i| {
                let mut visited = vec![false; n];
                dfs(&g, i, k, &mut visited, 0) > k
            })
            .count();
        println!("Case #{}: {}", tc, ans);
    }
}
