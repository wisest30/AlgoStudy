#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn count_points(rings: String) -> i32 {
        fn color_to_bitflag(b: u8) -> u8 {
            match b {
                b'R' => 1 << 0,
                b'G' => 1 << 1,
                b'B' => 1 << 2,
                _ => panic!("wrong color"),
            }
        }

        fn number_to_index(b: u8) -> usize {
            match b {
                b'0'..=b'9' => (b - b'0') as usize,
                _ => panic!("wrong number"),
            }
        }

        let mut rods = [0u8; 10];
        let mut it = rings.as_bytes().windows(2).step_by(2);

        for e in it {
            let bf = color_to_bitflag(e[0]);
            let idx = number_to_index(e[1]);
            rods[idx] |= bf;
        }

        let all_rgb = color_to_bitflag(b'R') | color_to_bitflag(b'G') | color_to_bitflag(b'B');
        rods.iter().filter(|&&e| e == all_rgb).count() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn count_points_typical() {
        let rings = String::from("B0B6G0R6R0R6G9");
        assert_eq!(1, Solution::count_points(rings));

        let rings = String::from("B0R0G0R9R0B0G0");
        assert_eq!(1, Solution::count_points(rings));

        let rings = String::from("G4");
        assert_eq!(0, Solution::count_points(rings));
    }
}
