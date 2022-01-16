impl Solution {
    pub fn min_moves(target: i32, max_doubles: i32) -> i32 {
        // return value : (operation count, new target, new max_doubles)
        fn process_even(target: i32, max_doubles: i32) -> (i32, i32, i32) {
            if max_doubles > 0 { (1, target / 2, max_doubles - 1) }
            else { (1, target - 1, max_doubles) }
        }
        fn process_odd(target: i32, max_doubles: i32) -> (i32, i32, i32) {
            if max_doubles == 0 { (target - 1, 1, 0) }
            else { (1, target - 1, max_doubles) }
        }
        
        let mut target = target;
        let mut max_doubles = max_doubles;
        let mut ret = 0;
        while target > 1 {
            let (cnt, new_target, new_max_doubles) = 
                if target % 2 == 0 { process_even(target, max_doubles) }
                else { process_odd(target, max_doubles) };
            
            ret += cnt; target = new_target; max_doubles = new_max_doubles
        }
        
        ret
    }
}
