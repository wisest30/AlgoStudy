struct Bitset {
    s : Vec::<u8>,
    f : bool,
    cnt : usize
}

impl Bitset {

    fn new(size: i32) -> Self {
        let size = size as usize;
        Bitset {
            s : vec![0; size],
            f : false,
            cnt : 0
        }
    }
    
    fn get(&self, idx: i32) -> u8 { self.s[idx as usize] ^ self.f as u8 }
    fn set(&mut self, idx: i32, val: u8) {
        if self.get(idx) != val {
            let idx = idx as usize;
            self.cnt -= self.s[idx] as usize;
            self.s[idx] ^= 1;
            self.cnt += self.s[idx] as usize;
        }
    }
    
    fn fix(&mut self, idx: i32) { self.set(idx, 1); }
    fn unfix(&mut self, idx: i32) { self.set(idx, 0); }
    fn flip(&mut self) { self.f = !self.f; }    
    fn all(&self) -> bool { self.count() as usize == self.s.len() }
    fn one(&self) -> bool { self.count() > 0 }
    fn count(&self) -> i32 { (if self.f { self.s.len() - self.cnt} else { self.cnt }) as i32 }
    fn to_string(&self) -> String { self.s.iter().map(|&x| (x ^ self.f as u8 + '0' as u8) as char).collect::<String>() }
}
