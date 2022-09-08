impl Solution {
    pub fn most_booked(n: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        meetings.sort_unstable();

        let n = n as usize;
        let mut rooms = vec![0i64; n];
        let mut cnts = vec![0; n];
        let mut cur_time = 0i64;
        for meeting in meetings {
            cur_time = std::cmp::max(cur_time, meeting[0] as i64);
            if let Some(i) = (0..n).filter(|&i| rooms[i] <= cur_time).min() {
                cnts[i] += 1;
                rooms[i] = cur_time + (meeting[1] - meeting[0]) as i64;
            } else if let Some((finish_time, i)) =
                rooms.iter().enumerate().map(|(i, v)| (*v, i)).min()
            {
                cnts[i] += 1;
                rooms[i] = finish_time + (meeting[1] - meeting[0]) as i64;
                cur_time = finish_time;
            } else {
                panic!();
            }
        }

        -cnts
            .into_iter()
            .enumerate()
            .map(|(i, v)| (v, -(i as i32)))
            .max()
            .unwrap()
            .1
    }
}
