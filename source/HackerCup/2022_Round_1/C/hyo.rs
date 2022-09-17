use std::io::Read;

type T = i64;
pub fn graham_scan(points: &Vec<(T, T)>) -> Vec<(T, T)> {
    use std::collections::HashSet;

    fn angle((x0, y0): (T, T), (x1, y1): (T, T)) -> f64 {
        assert_ne!((x0, y0), (x1, y1));

        let x = (x1 - x0) as f64;
        let y = (y1 - y0) as f64;

        y.atan2(x)
    }

    fn ccw((x0, y0): (T, T), (x1, y1): (T, T)) -> i32 {
        let d = x0 * y1 - x1 * y0;
        if d == 0 {
            0
        } else if d > 0 {
            1
        } else {
            -1
        }
    }

    // make unique points
    let mut v = points
        .iter()
        .cloned()
        .collect::<HashSet<(T, T)>>()
        .into_iter()
        .collect::<Vec<_>>();

    if v.len() <= 2 {
        v.sort_unstable();
        return v;
    }

    let min_x_idx = v.iter().enumerate().map(|(i, v)| (v, i)).min().unwrap().1;
    v.swap(0, min_x_idx);

    let (x0, y0) = v[0];
    v[1..].sort_unstable_by(|(x1, y1), (x2, y2)| {
        let a1 = angle((x0, y0), (*x1, *y1));
        let a2 = angle((x0, y0), (*x2, *y2));

        if a1 == a2 {
            let d1 = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
            let d2 = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);
            d1.cmp(&d2)
        } else {
            a1.partial_cmp(&a2).unwrap()
        }
    });

    let mut ret = vec![v[0], v[1]];
    for i in 2..v.len() {
        let mut last = ret.len() - 1;
        let mut llast = last - 1;

        while ret.len() >= 2
            && ccw(
                (ret[last].0 - ret[llast].0, ret[last].1 - ret[llast].1),
                (v[i].0 - ret[last].0, v[i].1 - ret[last].1),
            ) <= 0
        {
            ret.pop().unwrap();
            if ret.len() < 2 {
                break;
            }

            last -= 1;
            llast -= 1;
        }

        ret.push(v[i]);
    }

    ret
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for tc in 1..=test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let k = input.next().unwrap().parse::<i64>().unwrap();
        let d = input.next().unwrap().parse::<i64>().unwrap();

        let v = (0..n)
            .map(|_| {
                (
                    input.next().unwrap().parse::<i64>().unwrap(),
                    input.next().unwrap().parse::<i64>().unwrap(),
                )
            })
            .collect::<Vec<_>>();

        let max_x = v.last().unwrap().0;
        let v = graham_scan(&v);
        let n = v.len();

        let s = 0usize;
        let e = (0..n).filter(|&i| v[i].0 == max_x).last().unwrap();

        let dis = |i: usize, j: usize| {
            (v[i].0 - v[j].0) * (v[i].0 - v[j].0) + (v[i].1 - v[j].1) * (v[i].1 - v[j].1)
        };

        let mut g = vec![Vec::<(usize, i64)>::with_capacity(n); n];
        for i in 0..n {
            for j in i + 1..n {
                let distance = dis(i, j);
                if distance <= d * d {
                    let w = std::cmp::max(distance, k);
                    g[i].push((j, w));
                    g[j].push((i, w));
                }
            }
        }

        let mut visited = vec![false; n];
        let mut min_dis = vec![std::i64::MAX; n];
        min_dis[s] = 0;
        let mut cur = s;
        loop {
            visited[cur] = true;

            for &(nxt, w) in &g[cur] {
                min_dis[nxt] = std::cmp::min(min_dis[nxt], min_dis[cur] + w);
            }

            if cur == e {
                break;
            }

            if let Some((_, nxt)) = min_dis
                .iter()
                .enumerate()
                .map(|(i, val)| (val, i))
                .filter(|&(val, i)| !visited[i] && *val != std::i64::MAX)
                .min()
            {
                cur = nxt;
            } else {
                break;
            }
        }

        let mut ans: i64 = min_dis[e];
        if ans == std::i64::MAX {
            ans = -1;
        }

        println!("Case #{tc}: {ans}");
    }
}
