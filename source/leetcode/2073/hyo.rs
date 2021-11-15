impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        use std::cmp::min;
        let k = k as usize;
        let y = tickets[k];

        tickets[..=k].iter().map(|&x| min(x, y)).sum::<i32>()
        + tickets[k+1..].iter().map(|&x| min(x, y-1)).sum::<i32>()
    }
}
