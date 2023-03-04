use std::collections;
use std::io::Read;

fn main() {
    let mut stdin = std::io::stdin();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let n = input.next().unwrap().parse::<usize>().unwrap();

    for _ in 1..=n {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let a = (0..n)
            .map(|_| input.next().unwrap().parse::<i64>().unwrap())
            .collect::<Vec<_>>();

        let mut cnts = collections::HashMap::new();
        for &x in &a {
            *cnts.entry(x).or_insert(0) += 1;
        }

        let mut aa = a
            .iter()
            .enumerate()
            .map(|(i, &x)| (x, i))
            .collect::<Vec<_>>();

        aa.sort_unstable_by_key(|&(x, _)| cnts.get(&x).unwrap() * 1000000000 + x);

        let mut b = vec![0; n];
        let max_cnt = *cnts.get(&aa.last().unwrap().0).unwrap() as usize;
        (n - max_cnt..n).rev().for_each(|i| {
            let mut j = i;
            while j >= max_cnt {
                let k = j - max_cnt;
                b[aa[k].1] = aa[j].0;
                j = k;
            }

            b[aa[i].1] = aa[j].0;
        });

        let ans = b
            .iter()
            .map(|&x| x.to_string())
            .collect::<Vec<_>>()
            .join(" ");
        println!("{ans}");
    }
}
