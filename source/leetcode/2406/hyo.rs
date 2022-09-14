impl Solution {
    pub fn min_groups(mut intervals: Vec<Vec<i32>>) -> i32 {
        use std::collections::BinaryHeap;

        intervals.sort_unstable();
        let mut ret = 0;
        let mut heap = BinaryHeap::new();
        for iv in intervals {
            if !heap.is_empty() && -heap.peek().unwrap() < iv[0] {
                heap.pop().unwrap();
            } else {
                ret += 1;
            }

            heap.push(-iv[1]);
        }

        ret
    }
}
