impl Solution {
    pub fn count_points(rings: String) -> i32 {
        let mut arr = vec![0; 10];
        let rings = rings.chars().collect::<Vec<_>>();
        for i in (0..rings.len()).step_by(2) {
            arr[rings[i+1].to_digit(10).unwrap() as usize] |= 1 << "RGB".find(rings[i]).unwrap();
        }
        
        arr.iter().filter(|&&x| x == 0b111).count() as i32
    }
}
