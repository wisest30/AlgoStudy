impl Solution {
    pub fn smallest_trimmed_numbers(nums: Vec<String>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = nums[0].len();
        let mut vs = vec![Vec::new(); n + 1];

        for (i, num) in nums.into_iter().enumerate() {
            for len in 1..=n {
                let t = (num.chars().skip(n - len).collect::<String>(), i);
                vs[len].push(t);
            }
        }

        for v in &mut vs {
            v.sort_unstable();
        }

        queries
            .into_iter()
            .map(|v| vs[v[1] as usize][v[0] as usize - 1].1 as i32)
            .collect::<Vec<_>>()
    }
}
