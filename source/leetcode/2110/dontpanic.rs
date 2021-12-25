#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn get_descent_periods(prices: Vec<i32>) -> i64 {
        let mut it_desc = prices.windows(2).map(|x| x[0] - 1 == x[1]).peekable();
        let mut done = false;
        let mut l: i64 = 1;

        let it_lengthes_of_longest_periods = std::iter::from_fn(move || {
            let mut nextval = None;

            while let Some(b) = it_desc.next() {
                if b {
                    l += 1;
                } else {
                    nextval = Some(l);
                    l = 1;
                    break;
                }
            }

            // last value handling
            if !done && nextval.is_none() && it_desc.peek().is_none() {
                done = true;
                nextval = Some(l);
            }

            nextval
        });

        it_lengthes_of_longest_periods
            .map(|x| ((x * (x + 1)) / 2) as i64)
            .sum()
    }
}

impl Solution {
    pub fn get_descent_periods_vec_push(prices: Vec<i32>) -> i64 {
        let mut lengthes_of_longest_periods = Vec::<i64>::with_capacity(prices.len());

        let it_desc = prices.windows(2).map(|x| x[0] - 1 == x[1]);

        let mut l = 1;
        for b in it_desc {
            if b {
                l += 1;
            } else {
                lengthes_of_longest_periods.push(l); //yield l
                l = 1;
            }
        }
        lengthes_of_longest_periods.push(l); //yield l

        let ans: i64 = lengthes_of_longest_periods
            .iter()
            .map(|&x| ((x * (x + 1)) / 2) as i64)
            .sum();

        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn get_descent_periods_typical() {
        let prices = vec![1];
        assert_eq!(1, Solution::get_descent_periods(prices.clone()));
        assert_eq!(1, Solution::get_descent_periods_vec_push(prices.clone()));

        let prices = vec![2, 1];
        assert_eq!(3, Solution::get_descent_periods(prices.clone()));
        assert_eq!(3, Solution::get_descent_periods_vec_push(prices.clone()));

        let prices = vec![1, 2];
        assert_eq!(2, Solution::get_descent_periods(prices.clone()));
        assert_eq!(2, Solution::get_descent_periods_vec_push(prices.clone()));

        let prices = vec![3, 2, 1, 4];
        assert_eq!(7, Solution::get_descent_periods(prices.clone()));
        assert_eq!(7, Solution::get_descent_periods_vec_push(prices.clone()));

        let prices = vec![8, 6, 7, 7];
        assert_eq!(4, Solution::get_descent_periods(prices.clone()));
        assert_eq!(4, Solution::get_descent_periods_vec_push(prices.clone()));

        let prices = (1..=100000).rev().collect::<Vec<i32>>();
        assert_eq!(5000050000, Solution::get_descent_periods(prices.clone()));
        assert_eq!(
            5000050000,
            Solution::get_descent_periods_vec_push(prices.clone())
        );
    }
}
