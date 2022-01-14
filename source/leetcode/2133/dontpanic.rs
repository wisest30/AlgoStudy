#![allow(unused)]

struct Solution {}

impl Solution {
    pub fn check_valid(m: Vec<Vec<i32>>) -> bool {
        let l = m.len();
        for i in 0..l {
            let mut row_exist = vec![false; l];
            let mut col_exist = vec![false; l];
            for j in 0..l {
                row_exist[(m[i][j] - 1) as usize] = true;
                col_exist[(m[j][i] - 1) as usize] = true;
            }
            if !row_exist.iter().all(|&x| x) || !col_exist.iter().all(|&x| x) {
                return false;
            }
        }

        true
    }

    pub fn check_valid_iter(matrix: Vec<Vec<i32>>) -> bool {
        let l = matrix.len();
        let all_column_valid = (0..l)
            .map(|j| {
                matrix
                    .iter()
                    .map(|x| (x[j] - 1) as usize)
                    .fold(vec![false; l], |mut exist, x| {
                        exist[x] = true;
                        exist
                    })
                    .iter()
                    .all(|&x| x)
            })
            .all(|x| x);

        let all_row_valid = matrix
            .iter()
            .map(|v| {
                v.iter()
                    .map(|x| (x - 1) as usize)
                    .fold(vec![false; l], |mut exist, x| {
                        exist[x] = true;
                        exist
                    })
                    .iter()
                    .all(|&x| x)
            })
            .all(|x| x);

        all_column_valid && all_row_valid
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn typical_cases() {
        let matrix: Vec<Vec<i32>> = [
            vec![4, 5, 14, 8, 11, 14, 6, 2, 2, 12, 10, 9, 2, 7],
            vec![6, 6, 5, 13, 4, 2, 14, 8, 3, 6, 13, 4, 3, 13],
            vec![11, 14, 4, 12, 1, 6, 7, 11, 9, 10, 8, 13, 5, 6],
            vec![12, 10, 8, 1, 2, 5, 2, 6, 4, 4, 1, 3, 13, 3],
            vec![13, 3, 12, 9, 9, 4, 3, 12, 10, 9, 6, 1, 1, 14],
            vec![5, 7, 6, 3, 6, 7, 11, 3, 7, 3, 3, 10, 6, 12],
            vec![10, 11, 7, 5, 3, 11, 8, 13, 12, 1, 5, 5, 12, 1],
            vec![8, 1, 13, 6, 8, 3, 4, 1, 1, 14, 14, 6, 7, 5],
            vec![1, 9, 1, 14, 10, 8, 5, 4, 5, 11, 9, 11, 10, 10],
            vec![7, 4, 9, 7, 12, 9, 1, 10, 6, 7, 11, 8, 14, 4],
            vec![2, 8, 11, 4, 7, 12, 12, 5, 13, 8, 2, 2, 4, 11],
            vec![14, 12, 3, 10, 13, 10, 10, 14, 8, 2, 4, 12, 8, 9],
            vec![9, 13, 10, 2, 5, 13, 13, 7, 11, 13, 12, 14, 11, 8],
            vec![3, 2, 2, 11, 14, 1, 9, 9, 14, 5, 7, 7, 9, 2],
        ]
        .into();
        assert_eq!(false, Solution::check_valid(matrix.clone()));
        assert_eq!(false, Solution::check_valid_iter(matrix.clone()));
    }
}
