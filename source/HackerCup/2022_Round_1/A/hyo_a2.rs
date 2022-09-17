use std::io::Read;

pub fn get_pi<T>(s: &Vec<T>) -> Vec<usize>
where
    T: std::cmp::Eq,
{
    let n = s.len();
    let mut j = 0;
    let mut pi = vec![0; n];

    for i in 1..n {
        while j > 0 && s[i] != s[j] {
            j = pi[j - 1];
        }

        if s[i] == s[j] {
            j += 1;
            pi[i] = j;
        }
    }

    pi
}

pub fn kmp<T>(s: &Vec<T>, p: &Vec<T>) -> Vec<usize>
where
    T: std::cmp::Eq,
{
    let mut ret = Vec::new();
    let n = s.len();
    let m = p.len();
    let mut j = 0;
    let pi = get_pi::<T>(p);
    for i in 0..n {
        while j > 0 && s[i] != p[j] {
            j = pi[j - 1];
        }
        if s[i] == p[j] {
            if j == m - 1 {
                ret.push(i + 1 - m);
                j = pi[j];
            } else {
                j += 1;
            }
        }
    }

    ret
}

fn is_rotate(a: &Vec<usize>, b: &Vec<usize>) -> bool {
    let mut a = a.clone();
    a.extend(a.clone().into_iter());

    !kmp::<usize>(&a, &b).is_empty()
}

fn is_phase(a: &Vec<usize>) -> bool {
    let n = a.len();
    for len in 1..n {
        if n % len != 0 {
            continue;
        }

        let mut ans = true;
        for i in len..n {
            if a[i - len] != a[i] {
                ans = false;
                break;
            }
        }

        if ans {
            return true;
        }
    }

    false
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
                is_phase(&a)
            } else {
                rotate
            }
        } else if n == 2 {
            if a[0] == a[1] {
                true
            } else if k % 2 == 0 {
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
