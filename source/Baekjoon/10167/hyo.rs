use std::io::{Read, Write};

const GROUP_COUNT: usize = 60;

#[derive(Default, Clone)]
struct SumNode {
    total_sum: i64,
    max_range_sum: i64,
    left_min_sum: i64,
    left_max_sum: i64,
}

struct RangeMaxSum {
    val: Vec<i64>,
    sum_nodes: Vec<SumNode>,
}

impl RangeMaxSum {
    fn new(n: usize) -> Self {
        Self {
            val: vec![0; n],
            sum_nodes: vec![SumNode::default(); (n + GROUP_COUNT - 1) / GROUP_COUNT],
        }
    }

    fn add_line(&mut self, line: &[(i32, i32, i64)]) {
        line.iter().for_each(|(_, x, w)| self.add(*x as usize, *w));
    }

    fn add(&mut self, i: usize, w: i64) {
        self.val[i] += w;

        let sum_node = &mut self.sum_nodes[i / GROUP_COUNT];
        *sum_node = SumNode::default();

        let mut cur_sum = 0i64;
        let mut min_sum = 0i64;
        let mut max_sum = 0i64;
        let start_index = i / GROUP_COUNT * GROUP_COUNT;
        for j in 0..GROUP_COUNT {
            if start_index + j >= self.val.len() {
                break;
            }

            cur_sum += self.val[start_index + j];
            min_sum = min_sum.min(cur_sum);
            max_sum = max_sum.max(cur_sum - min_sum);
            sum_node.left_min_sum = sum_node.left_min_sum.min(cur_sum);
            sum_node.left_max_sum = sum_node.left_max_sum.max(cur_sum);
        }

        sum_node.total_sum = cur_sum;
        sum_node.max_range_sum = max_sum;
    }

    fn max_sum(&self) -> i64 {
        let mut ret = self
            .sum_nodes
            .iter()
            .map(|s| s.max_range_sum)
            .max()
            .unwrap();
        let mut cur_sum = 0i64;
        let mut min_sum = 0i64;
        for i in 0..self.sum_nodes.len() {
            let cur_max_sum = cur_sum + self.sum_nodes[i].left_max_sum;

            ret = ret.max(cur_max_sum - min_sum);

            min_sum = min_sum.min(cur_sum + self.sum_nodes[i].left_min_sum);
            cur_sum += self.sum_nodes[i].total_sum;
        }

        ret
    }
}

struct Problem {
    n: usize,
    pointers: Vec<(i32, i32, i64)>,
    weight_map: Vec<Vec<i64>>,
    lines: Vec<Vec<(i32, i32, i64)>>,
}

impl Problem {
    fn new(n: usize, pointers: Vec<(i32, i32, i64)>) -> Self {
        Self {
            n,
            pointers,
            weight_map: Vec::new(),
            lines: Vec::new(),
        }
    }

    fn solve(&mut self) -> i64 {
        self.refine_pointers();
        self.generate_weight_map();
        self.generate_lines();

        let mut ans = 0;
        for y0 in 0..self.n {
            let mut range_max_sum = RangeMaxSum::new(self.n);
            for y1 in y0 + 1..=self.n {
                range_max_sum.add_line(&self.lines[y1 - 1]);
                ans = ans.max(range_max_sum.max_sum());
            }
        }

        ans
    }

    fn refine_pointers(&mut self) {
        use std::collections::HashMap;
        fn generate_invert_map(mut v: Vec<i32>) -> HashMap<i32, usize> {
            v.sort();
            v.dedup();

            v.iter().enumerate().map(|(i, &p)| (p, i)).collect()
        }

        let x_map =
            generate_invert_map(self.pointers.iter().map(|(x, _, _)| *x).collect::<Vec<_>>());
        let y_map =
            generate_invert_map(self.pointers.iter().map(|(_, y, _)| *y).collect::<Vec<_>>());

        for (x, y, _) in self.pointers.iter_mut() {
            *x = *x_map.get(x).unwrap() as i32;
            *y = *y_map.get(y).unwrap() as i32;
        }
    }

    fn generate_weight_map(&mut self) {
        let mut map = vec![vec![0; self.n]; self.n];

        for &(x, y, w) in self.pointers.iter() {
            map[x as usize][y as usize] = w;
        }

        self.weight_map = map;
    }

    fn generate_lines(&mut self) {
        self.lines = vec![Vec::new(); self.n];
        for point in self.pointers.iter() {
            self.lines[point.0 as usize].push(*point);
        }
    }
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let pointers = (0..n)
        .map(|_| {
            (
                input.next().unwrap().parse::<i32>().unwrap(),
                input.next().unwrap().parse::<i32>().unwrap(),
                input.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect::<Vec<_>>();

    let ans = Problem::new(n, pointers).solve();

    writeln!(stdout, "{}", ans).ok();
}
