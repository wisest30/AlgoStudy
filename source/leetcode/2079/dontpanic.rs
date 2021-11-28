//#![allow(unused)]
//struct Solution {}

impl Solution {
    pub fn watering_plants(plants: Vec<i32>, capacity: i32) -> i32 {
        plants
            .iter()
            .enumerate()
            .fold((0, capacity), |(steps, water), (i, &need)| {
                if water >= need {
                    (steps + 1, water - need)
                } else {
                    (steps + 1 + i * 2, capacity - need)
                }
            })
            .0 as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn watering_plants_typical() {
        let plants = vec![2, 2, 3, 3];
        let capacity = 5;
        let expected = 14;
        assert_eq!(expected, Solution::watering_plants(plants, capacity));

        let plants = vec![1, 1, 1, 4, 2, 3];
        let capacity = 4;
        let expected = 30;
        assert_eq!(expected, Solution::watering_plants(plants, capacity));

        let plants = vec![7, 7, 7, 7, 7, 7, 7];
        let capacity = 8;
        let expected = 49;
        assert_eq!(expected, Solution::watering_plants(plants, capacity));
    }
}
