#![allow(unused)]

// ref: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/discuss/1563739/

pub fn minimized_maximum(n: i32, qtts: Vec<i32>) -> i32 {
    let mut left: i32 = 1;
    let mut right: i32 = qtts.iter().max().unwrap().clone();

    while left < right {
        let x: i32 = (left + right) / 2;
        let sum: i32 = qtts.iter().map(|q| (q + x - 1) / x).sum();
        if sum > n {
            left = x + 1;
        } else {
            right = x;
        }
    };

    left
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn minimized_maximum_typical() {
        assert_eq!(3, minimized_maximum(6, vec![11,6]));
        assert_eq!(5, minimized_maximum(7, vec![15,10,10]));
        assert_eq!(100000, minimized_maximum(1, vec![100000]));
    }
}
