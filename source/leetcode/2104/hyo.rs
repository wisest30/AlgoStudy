impl Solution {
    pub fn sub_array_ranges(nums: Vec<i32>) -> i64 {
        // O(n) solution
        
        fn f<Func>(
            func: Func,
            len: usize
        ) -> (Vec<i32>, Vec<i32>)
        where Func : Fn(usize, usize) -> bool
        {
            let mut left = vec![-1; len];
            let mut right = vec![len as i32; len];
            let mut stack: Vec<usize> = Vec::new();
            for i in 0..left.len() {
                while !stack.is_empty() && func(*stack.last().unwrap(), i) {
                    right[*stack.last().unwrap()] = i as i32;
                    stack.pop();
                }
                
                if !stack.is_empty() {
                    left[i] = *stack.last().unwrap() as i32;
                }
                stack.push(i);                
            };
            
            (left, right)
        };
        
        let (larger_left, larger_right) = f(
            |x: usize, y: usize| -> bool { nums[x] < nums[y] },
            nums.len()
        );
        
        let (small_left, small_right) = f(
            |x: usize, y: usize| -> bool { nums[x] > nums[y] },
            nums.len()
        );
        
        let mut ret = 0i64;
        for i in 0..nums.len() {
            ret += nums[i] as i64 * (i as i64 - larger_left[i] as i64) * (larger_right[i] as i64 - i as i64);
            ret -= nums[i] as i64 * (i as i64 - small_left[i] as i64) * (small_right[i] as i64 - i as i64);
        }
        
        ret
    }
}
