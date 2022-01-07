impl Solution {
    pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
        asteroids.sort();
        asteroids.iter().fold(mass as i64, |acc, &x| if acc >= x as i64 { acc + x as i64 } else { 0 }) > 0
    }
}
