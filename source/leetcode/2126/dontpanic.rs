#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
        asteroids.sort();
        asteroids
            .iter()
            .try_fold(mass as i64, |acc, &x| match acc >= x as i64 {
                true => Some(acc + x as i64),
                false => None,
            })
            .is_some()
    }

    // from https://leetcode.com/problems/destroying-asteroids/discuss/1667702/Java-O(n)-18-ms-faster-than-99.53-of-Java-online-submissions
    pub fn asteroids_destroyed_big_o_n(mass: i32, asteroids: Vec<i32>) -> bool {
        let mut mass = mass as i64;
        let mut data = vec![0; 100001];
        let mut min = 100001;
        let mut max = -1;

        for &a in asteroids.iter() {
            min = std::cmp::min(min, a);
            max = std::cmp::max(max, a);
            data[a as usize] += 1;
        }

        for i in min..=max {
            if mass < i as i64 && data[i as usize] != 0 {
                return false;
            }

            mass += i as i64 * data[i as usize];
        }

        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let mass = 10;
        let asteroids: Vec<i32> = [3, 9, 19, 5, 21].into_iter().collect();
        let expected = true;

        let actual = Solution::asteroids_destroyed(mass, asteroids.clone());
        assert_eq!(expected, actual);
        let actual = Solution::asteroids_destroyed_big_o_n(mass, asteroids.clone());
        assert_eq!(expected, actual);

        let mass = 5;
        let asteroids: Vec<i32> = [4, 9, 23, 4].into_iter().collect();
        let expected = false;

        let actual = Solution::asteroids_destroyed(mass, asteroids.clone());
        assert_eq!(expected, actual);
        let actual = Solution::asteroids_destroyed_big_o_n(mass, asteroids.clone());
        assert_eq!(expected, actual);
    }
}
