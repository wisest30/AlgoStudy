//#![allow(unused)]
//struct Solution {}

impl Solution {
    pub fn max_distance(colors: Vec<i32>) -> i32 {
        let first = colors.first().unwrap().clonae();
        let last = colors.last().unwrap().clone();

        let it = colors.iter();
        let itrev = it.clone().rev();
        let itzip = it.zip(itrev);

        // let lmax = colors.len()
        //     - 1
        //     - colors
        //         .iter()
        //         .enumerate()
        //         .find(|(_, &n)| n != last)
        //         .unwrap()
        //         .0;
        // let rmax = colors.len()
        //     - 1
        //     - colors
        //         .iter()
        //         .rev()
        //         .enumerate()
        //         .find(|(_, &n)| n != first)
        //         .unwrap()
        //         .0;
        // std::cmp::max(lmax, rmax) as i32

        (colors.len()
            - 1
            - itzip
                .enumerate()
                .find(|(_, (&x, &y))| x != last || y != first)
                .unwrap()
                .0) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn max_distance_typical() {
        let v = vec![1, 1, 1, 6, 1, 1, 1];
        assert_eq!(3, Solution::max_distance(v));

        let v = vec![1, 8, 3, 8, 3];
        assert_eq!(4, Solution::max_distance(v));

        let v = vec![0, 1];
        assert_eq!(1, Solution::max_distance(v));
    }
}
