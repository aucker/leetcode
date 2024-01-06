impl Solution {
    pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
        let mut jobs: Vec<(i32, i32, i32)> = start_time.iter().zip(end_time.iter()).zip(profit.iter()).map(|((s, e), p)| (*s, *e, *p)).collect();
        jobs.sort_by(|a, b| a.1.cmp(&b.1));
        let mut dp: Vec<i32> = vec![0; jobs.len()];
        dp[0] = jobs[0].2;
        for i in 1..jobs.len() {
            let mut j = i - 1;
            while j >= 0 && jobs[j].1 > jobs[i].0 {
                j -= 1;
            }
            dp[i] = std::cmp::max(dp[i - 1], dp[j] + jobs[i].2);
        }
        dp[jobs.len() - 1]
    }
}