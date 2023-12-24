impl Solution {
    pub fn min_operations(s: String) -> i32 {
        // let mut res = 0;
        // let n = s.len();
        // for i in 0..n {
        //     if s.chars().nth(i).unwrap() as usize - b'0' as usize != i % 2 {
        //         res += 1;
        //     }
        // }
        // std::cmp::min(res, n as i32 - res)

        // let mut res = 0;
        // for (i, c) in s.chars().enumerate() {
        //     if c as usize - b'0' as usize != i % 2 {
        //         res += 1;
        //     }
        // }
        // std::cmp::min(res, s.len() as i32 - res)

        let (mut cnt0, mut cnt1) = (0, 0);
        for i in 0..s.len() {
            if i % 2 == 0 {
                if s.chars().nth(i).unwrap() == '0' {
                    cnt1 += 1;
                } else {
                    cnt0 += 1;
                }
            } else {
                if s.chars().nth(i).unwrap() == '1' {
                    cnt1 += 1;
                } else {
                    cnt0 += 1;
                }
            }
        }
        std::cmp::min(cnt0, cnt1)
    }
}