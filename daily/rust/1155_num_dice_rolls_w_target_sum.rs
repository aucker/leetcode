impl Solution {
    const M: i32 = 1_000_000_007;
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        // let mut dp = vec![vec![0; target as usize + 1]; n as usize + 1];
        // let m = 1000000007;
        // for i in 1..=n as usize {
        //     for j in 1..=target as usize {
        //         if i == 1 && j <= k as usize {
        //             dp[i][j] = 1;
        //         } else {
        //             for l in 1..=k as usize {
        //                 if j >= l {
        //                     dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % m;
        //                 }
        //             }
        //         }
        //     }
        // }
        // dp[n as usize][target as usize]


        let mut dp = vec![vec![-1; target as usize + 1]; n as usize + 1];
        return Solution::solve(n, k, target, &mut dp) as i32;
    }

    fn solve(n: i32, k: &i32, target: i32, dp: &mut Vec<Vec<i32>>) -> i32 {
        if n == 0 && target == 0 { return 1; }
        if n <= 0 { return 0; }
        if dp[n as usize][target as usize] != -1 { return dp[n as usize][target as usize]; }
        let mut res = 0;
        for i in 1..=std::cmp::min(*k, target) {
            res = (res + Self::solve(n-1, k, target-i, dp)) % Self::M;
        }
        dp[n as usize][target as usize] = res;
        dp[n as usize][target as usize]
    }

}