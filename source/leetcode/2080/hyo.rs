struct RangeFreqQuery {
    idxs: Vec<Vec<usize>>
}

impl RangeFreqQuery {
    fn new(arr: Vec<i32>) -> Self {
        let mut idxs = vec![Vec::new(); 10001];
        for (i, &val) in arr.iter().enumerate() {
            idxs[val as usize].push(i);
        }
        
        RangeFreqQuery { idxs }
    }
    
    fn query(&self, left: i32, right: i32, value: i32) -> i32 {
        let left = left as usize;
        let right = right as usize;
        
        // partition_point()는 원래 rust 1.52 이상 버전엔 표준 라이브러리에 있는 함수인데 릿코드의 컴파일러 버전이 낮아서인지 에러가 나와서 작성함.
        // 원본 소스코드 : https://doc.rust-lang.org/src/core/slice/mod.rs.html#3465-3467
        // 레퍼런스 : https://doc.rust-lang.org/std/primitive.slice.html#method.partition_point
        fn partition_point<P>(v: &Vec<usize>, mut pred: P) -> usize
        where P: FnMut(&usize) -> bool,
        {
            use std::cmp::Ordering::{Greater, Less};
            v.binary_search_by(|x| if pred(x) { Less } else { Greater }).unwrap_or_else(|i| i)
        }
        
        let v = &self.idxs[value as usize];
        let l = partition_point(v, |&i| i < left);
        let r = partition_point(v, |&i| i <= right);

        (r - l) as i32
    }
}
