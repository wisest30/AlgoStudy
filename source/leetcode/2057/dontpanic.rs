#![allow(unused)]

pub fn smallest_equal(nums: Vec<i32>) -> i32 {
    let found = nums.iter().enumerate().find(|(i, &x)| i % 10 == x as usize);
    match found {
        Some((i, _)) => i as i32,
        None => -1,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn smallest_equal_typical() {
        let v = vec![0, 1, 2];
        assert_eq!(0, smallest_equal(v));

        let v = vec![4, 3, 2, 1];
        assert_eq!(2, smallest_equal(v));

        let v = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
        assert_eq!(-1, smallest_equal(v));

        let v = vec![2, 1, 3, 5, 2];
        assert_eq!(1, smallest_equal(v));
    }
}
