use std::cmp::min;
impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut dp: Vec<i32> = vec![];
        let size = cost.len();
        if size <= 2 {
            return min(cost[0], cost[1]);
        }
        for i in 0..size {
            if i == 0 {
                dp.push(cost[i]);     
            } else if i == 1 {
                dp.push(cost[i]);
            } else {
                dp.push(min(cost[i]+ dp[i - 1], cost[i]+ dp[i-2]));
            }
        }
        min(dp[dp.len()-1], dp[dp.len()-2])
    }
}