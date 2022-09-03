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
        let mut scene = (0..r)
            .map(|_| {
                input
                    .next()
                    .unwrap()
                    .replace('.', "?")
                    .chars()
                    .collect::<Vec<_>>()
            })
            .collect::<Vec<_>>();

        const DY: [i32; 4] = [-1, 0, 0, 1];
        const DX: [i32; 4] = [0, -1, 1, 0];
        let mut lonely_trees = Vec::<(usize, usize)>::new();
        let is_tree =
            |scene: &Vec<Vec<char>>, y: usize, x: usize| scene[y][x] == '^' || scene[y][x] == '?';
        let counter_friends = |scene: &Vec<Vec<char>>, y: usize, x: usize| {
            (0..4)
                .map(|i| (y as i32 + DY[i], x as i32 + DX[i]))
                .filter(|&(ny, nx)| {
                    ny >= 0
                        && ny < r as i32
                        && nx >= 0
                        && nx < c as i32
                        && is_tree(scene, ny as usize, nx as usize)
                })
                .count()
        };

        (0..r).for_each(|y| {
            (0..c)
                .filter(|&x| is_tree(&scene, y, x) && counter_friends(&scene, y, x) < 2)
                .for_each(|x| lonely_trees.push((y, x)))
        });

        let mut possible = true;
        while let Some((y, x)) = lonely_trees.pop() {
            if scene[y][x] == '^' {
                possible = false;
                break;
            }

            scene[y][x] = '.';
            (0..4)
                .map(|i| (y as i32 + DY[i], x as i32 + DX[i]))
                .filter(|&(ny, nx)| ny >= 0 && ny < r as i32 && nx >= 0 && nx < c as i32)
                .map(|(ny, nx)| (ny as usize, nx as usize))
                .filter(|&(ny, nx)| is_tree(&scene, ny, nx) && counter_friends(&scene, ny, nx) == 1)
                .for_each(|(y, x)| lonely_trees.push((y, x)));
        }

        if possible {
            println!("Case #{tc}: Possible");
            let mut buf = String::new();
            scene.into_iter().for_each(|row| {
                buf.push_str(&row.into_iter().collect::<String>().replace('?', "^"));
                buf.push('\n');
            });
            buf.pop();

            println!("{buf}");
        } else {
            println!("Case #{tc}: Impossible");
        }
    }
}

