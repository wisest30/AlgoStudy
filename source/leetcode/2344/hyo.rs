impl Solution {
    pub fn min_operations(mut nums: Vec<i32>, nums_divide: Vec<i32>) -> i32 {
        fn gcd(a: i32, b: i32) -> i32 {
            if b == 0 {
                a
            } else {
                gcd(b, a % b)
            }
        }

        let first = nums_divide[0];
        let mut g = nums_divide
            .into_iter()
            .fold(first, |acc, cur| gcd(acc, cur));

        nums.sort_unstable();
        for (i, num) in nums.into_iter().enumerate() {
            if g % num == 0 {
                return i as i32;
            }
        }

        -1
    }
}
