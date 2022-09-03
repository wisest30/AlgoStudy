pub fn upper_bound<T>(arr: &[T], val: T) -> usize
where
    T: Ord,
{
    if arr.is_empty() {
        0
    } else {
        let mut left = 0usize;
        let mut right = arr.len();
        while left + 1 < right {
            let m = (left + right) / 2;
            if arr[m] <= val {
                left = m;
            } else {
                right = m;
            }
        }

        assert!(left + 1 == right);
        if arr[left] <= val {
            left + 1
        } else {
            left
        }
    }
}

impl Solution {
    pub fn answer_queries(mut nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        nums.sort_unstable();
        for i in 1..nums.len() {
            nums[i] += nums[i - 1];
        }

        queries
            .into_iter()
            .map(|q| upper_bound(&nums, q) as i32)
            .collect::<Vec<_>>()
    }
}
