impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        assert!(n >= 1);
        let mut res = vec![0; n];
        res[0] = 1;
        res[1] = 2;
        for i in 2..n {
            res[i as usize] = res[i as usize - 1] + res[i as usize - 2];
        }
        res[n as usize - 1]
    }
}