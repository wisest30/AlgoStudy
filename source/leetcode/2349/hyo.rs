use std::collections::{BTreeSet, HashMap};

#[derive(Default)]
struct NumberContainers {
    map: HashMap<i32, i32>,
    inv_map: HashMap<i32, BTreeSet<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumberContainers {
    fn new() -> Self {
        Default::default()
    }

    fn change(&mut self, index: i32, number: i32) {
        if let Some(val) = self.map.remove(&index) {
            self.inv_map.get_mut(&val).unwrap().remove(&index);
        }

        self.map.insert(index, number);
        (*self.inv_map.entry(number).or_insert(BTreeSet::<i32>::new())).insert(index);
    }

    fn find(&self, number: i32) -> i32 {
        if let Some(set) = self.inv_map.get(&number) {
            for &ret in set {
                return ret;
            }
            -1
        } else {
            -1
        }
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * let obj = NumberContainers::new();
 * obj.change(index, number);
 * let ret_2: i32 = obj.find(number);
 */
