impl Solution {
    pub fn earliest_full_bloom(plant_time: Vec<i32>, grow_time: Vec<i32>) -> i32 {
        let n = plant_time.len();
        let mut order = (0..n).collect::<Vec<usize>>();
        order.sort_by_key(|&i| -grow_time[i]);
        let mut ret = i32::MAX;
        let mut plant_sum = 0;
        order.into_iter().map(|i| {
            plant_sum += plant_time[i];
            plant_sum + grow_time[i]
        }).max().unwrap()
    }
}
