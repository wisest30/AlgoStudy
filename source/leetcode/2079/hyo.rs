impl Solution {
    pub fn watering_plants(plants: Vec<i32>, capacity: i32) -> i32 {
        plants
        .iter()
        .enumerate()
        .fold((0, capacity),
            |acc, (i, &val)|
            if acc.1 >= plants[i] { (acc.0 + 1, acc.1 - plants[i]) }
            else { (acc.0 + 1 + i as i32 * 2, capacity - plants[i]) }
        ).0
    }
}
