fn construct_graph(parents: &Vec<i32>) -> Vec<Vec<usize>> {
    let n = parents.len();
    let mut ret = vec![vec![0usize; 0]; n];
    for i in 1..n {
        ret[parents[i] as usize].push(i);
    }

    ret
}

fn solve(parents: Vec<i32>, nums: Vec<i32>, v: usize) -> Vec<i32> {
    let n = parents.len();
    let max_num = 100001usize;
    let g = construct_graph(&parents);
    let mut ret = vec![1; n];
    let mut has = vec![false; max_num];
    let mut x = 1usize;

    let mut p = v;
    loop {
        let mut st = Vec::new();
        st.push(p);
        while !st.is_empty() {
            let cur = st.pop().unwrap();
            has[nums[cur] as usize] = true;
            for &nxt in &g[cur] {
                if has[nums[nxt] as usize] == false {
                    st.push(nxt);
                }
            }
        }
        
        while x < max_num && has[x] == true {
            x += 1;
        }
        
        ret[p] = x as i32;
        if parents[p] == -1 {
            break;
        } else {
            p = parents[p] as usize;
        }
    }
    
    ret
}

impl Solution {    
    pub fn smallest_missing_value_subtree(parents: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        let n = parents.len();
       
        let mut v = nums.iter().position(|&x| x == 1);

        if v == None {
            vec![1; n]
        } else {
            solve(parents, nums, v.unwrap())
        }
    }
}
