// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn spiral_matrix(r: i32, c: i32, head: Option<Box<ListNode>>) -> Vec<Vec<i32>> {
        let dy = [0, 1, 0, -1];
        let dx = [1, 0, -1, 0];
        let mut ret = vec![vec![-1; c as usize]; r as usize];
        
        let mut h = head;
        let mut y = 0;
        let mut x = 0;
        let mut d = 0;
        while h != None {
            ret[y as usize][x as usize] = h.as_ref().unwrap().val;
            h = h.unwrap().next;
            
            let mut ny = y + dy[d];
            let mut nx = x + dx[d];
            if ny < 0 || ny >= r || nx < 0 || nx >= c || ret[ny as usize][nx as usize] != -1 {
                d = (d + 1) % 4;
                ny = y + dy[d];
                nx = x + dx[d];
            }
            
            y = ny;
            x = nx;
        }
        
        ret
    }
}
