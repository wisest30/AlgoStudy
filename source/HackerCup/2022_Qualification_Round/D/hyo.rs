use std::cmp::min;
use std::collections::HashMap;
use std::io::Read;
use std::mem::swap;

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();

    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();
        let q = input.next().unwrap().parse::<usize>().unwrap();

        let mut g = vec![vec![(0usize, 0usize); 0]; n + 1];
        let mut edges = HashMap::<(usize, usize), usize>::new();

        for _ in 0..m {
            let u = input.next().unwrap().parse::<usize>().unwrap();
            let v = input.next().unwrap().parse::<usize>().unwrap();
            let c = input.next().unwrap().parse::<usize>().unwrap();

            g[u].push((c, v));
            g[v].push((c, u));

            edges.insert((u, v), c);
            edges.insert((v, u), c);
        }

        let mut query_vec = vec![(0usize, 0usize); 0];
        let mut query_map = HashMap::<(usize, usize), usize>::new();
        for _ in 0..q {
            let mut x = input.next().unwrap().parse::<usize>().unwrap();
            let mut y = input.next().unwrap().parse::<usize>().unwrap();
            if x > y {
                swap(&mut x, &mut y);
            }
            query_vec.push((x, y));
            query_map.insert((x, y), 0);
        }

        let mut big_nodes = vec![0usize; 0];
        for i in 1..=n {
            if g[i].len() > 1000 {
                big_nodes.push(i);
                continue;
            }

            for j in 0..g[i].len() {
                for k in j + 1..g[i].len() {
                    let mut x = g[i][j].1;
                    let mut y = g[i][k].1;
                    let c = min(g[i][j].0, g[i][k].0);

                    if x > y {
                        swap(&mut x, &mut y);
                    }

                    if let Some(e) = query_map.get_mut(&(x, y)) {
                        *e += c;
                    }
                }
            }
        }

        for (&(x, y), e) in query_map.iter_mut() {
            for &i in &big_nodes {
                let c1 = edges.get(&(x, i)).unwrap_or(&0);
                let c2 = edges.get(&(i, y)).unwrap_or(&0);

                *e += min(c1, c2);
            }
        }

        let mut ans = String::new();
        for query in query_vec {
            let e = query_map.get_mut(&query).unwrap();
            let add = 2 * edges.get(&query).unwrap_or(&0);
            ans.push_str(&(*e + add).to_string());
            ans.push(' ');
        }

        println!("Case #{tc}: {}", ans);
    }
}

