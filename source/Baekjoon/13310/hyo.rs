use std::io::{Read, Write};

type T = i64;
pub fn graham_scan(mut v: Vec<(T, T)>) -> Vec<(T, T)> {
    use std::cmp::Ordering;

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

    v.sort_unstable();
    v.dedup();

    if v.len() <= 2 {
        return v;
    }

    let min_x_idx = v.iter().enumerate().map(|(i, v)| (v, i)).min().unwrap().1;
    v.swap(0, min_x_idx);

    let (x0, y0) = v[0];
    v[1..].sort_unstable_by(|(x1, y1), (x2, y2)| {
        let cw = ccw((x1 - x0, y1 - y0), (x2 - x0, y2 - y0));
        match cw {
            0 => {
                let d1 = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
                let d2 = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);
                d1.cmp(&d2)
            }
            1 => Ordering::Less,
            -1 => Ordering::Greater,
            _ => panic!(),
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

pub fn rotating_calipers(converx_hull_points: &Vec<(T, T)>) -> T {
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

    fn dist_squre((x0, y0): (T, T), (x1, y1): (T, T)) -> T {
        (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)
    }

    let mut ret = 0;

    let mut j = 0;
    for i in 0..converx_hull_points.len() {
        while j + 1 < converx_hull_points.len()
            && ccw(
                (
                    converx_hull_points[i + 1].0 - converx_hull_points[i].0,
                    converx_hull_points[i + 1].1 - converx_hull_points[i].1,
                ),
                (
                    converx_hull_points[j + 1].0 - converx_hull_points[j].0,
                    converx_hull_points[j + 1].1 - converx_hull_points[j].1,
                ),
            ) >= 0
        {
            ret = ret.max(dist_squre(converx_hull_points[i], converx_hull_points[j]));
            j += 1;
        }
        ret = ret.max(dist_squre(converx_hull_points[i], converx_hull_points[j]));
    }

    ret
}

struct Star {
    x: i64,
    y: i64,
    dx: i64,
    dy: i64,
}

impl Star {
    pub fn new(x: i64, y: i64, dx: i64, dy: i64) -> Self {
        Self { x, y, dx, dy }
    }

    pub fn pos(&self, t: i64) -> (i64, i64) {
        (self.x + self.dx * t, self.y + self.dy * t)
    }
}

struct Problem {
    n: usize,
    t: i64,
    stars: Vec<Star>,
}

impl Problem {
    fn new(n: usize, t: i64, stars: Vec<Star>) -> Self {
        Self { n, t, stars }
    }

    fn max_diameter(&self, t: i64) -> i64 {
        let points = self
            .stars
            .iter()
            .map(|star| star.pos(t))
            .collect::<Vec<_>>();

        let converx_hull_points = graham_scan(points);

        rotating_calipers(&converx_hull_points)
    }

    fn solve(&mut self) -> String {
        let mut l = 0i64;
        let mut r = self.t;
        while l + 2 < r {
            let lm = (l + l + r) / 3;
            let rm = (l + r + r) / 3;
            if self.max_diameter(lm) > self.max_diameter(rm) {
                l = lm;
            } else {
                r = rm;
            }
        }

        let mut min_val = i64::MAX;
        let mut min_idx = l;
        for i in l..=r {
            let val = self.max_diameter(i);
            if val < min_val {
                min_val = val;
                min_idx = i;
            }
        }

        let mut ret = min_idx.to_string();
        ret.push('\n');
        ret += &min_val.to_string();

        ret
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let t = input.next().unwrap().parse::<i64>().unwrap();
    let stars = (0..n)
        .map(|_| {
            Star::new(
                input.next().unwrap().parse::<i64>().unwrap(),
                input.next().unwrap().parse::<i64>().unwrap(),
                input.next().unwrap().parse::<i64>().unwrap(),
                input.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect::<Vec<_>>();

    let ans = Problem::new(n, t, stars).solve();

    writeln!(stdout, "{}", ans).ok();
}
