type NodeType = i32;
pub fn edges_to_dig(n: usize, edges: &Vec<Vec<NodeType>>) -> Vec<Vec<NodeType>> {
    let mut g = vec![vec![]; n];
    for e in edges {
        g[e[0] as usize - 1].push(e[1] - 1);
    }

    g
}

fn topsort(g: &Vec<Vec<NodeType>>) -> Vec<NodeType> {
    let n = g.len();
    let mut indegree = vec![0usize; n];
    for u in 0..n {
        for &v in &g[u] {
            indegree[v as usize] += 1;
        }
    }

    let mut ret = Vec::<NodeType>::new();
    for u in 0..n {
        if indegree[u] == 0 {
            ret.push(u as NodeType);
        }
    }

    let mut i = 0;
    while i < ret.len() {
        let u = ret[i];
        for &v in &g[u as usize] {
            indegree[v as usize] -= 1;
            if indegree[v as usize] == 0 {
                ret.push(v as NodeType);
            }
        }

        i += 1;
    }

    if ret.len() == n {
        ret
    } else {
        Vec::new()
    }
}

impl Solution {
    pub fn build_matrix(
        k: i32,
        row_conditions: Vec<Vec<i32>>,
        col_conditions: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        let n = k as usize;
        let g_row = edges_to_dig(n, &row_conditions);
        let g_col = edges_to_dig(n, &col_conditions);

        let v_row = topsort(&g_row);
        let v_col = topsort(&g_col);

        if v_row.is_empty() || v_col.is_empty() {
            vec![]
        } else {
            let mut pos_x = vec![0; n];
            let mut pos_y = vec![0; n];

            for i in 0..n {
                pos_y[v_row[i] as usize] = i;
                pos_x[v_col[i] as usize] = i;
            }

            let mut ret = vec![vec![0; n]; n];

            for i in 0..n {
                ret[pos_y[i]][pos_x[i]] = i as i32 + 1;
            }

            ret
        }
    }
}
