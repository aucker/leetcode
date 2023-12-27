impl Solution {
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
        let n = colors.len();
        let mut dp = vec![-1; n];
        Self::cal_min_cost(n-1, &colors, needed_time, &mut dp, 'A', needed_time[n-1])
    }

    fn cal_min_cost(i: i32, colors: &String, needed_time: &Vec<i32>, memo: Vec<i32>, prev_color: char, prev_time: i32) -> i32 {
        if i < 0 { return 0; } // base case: return beginning sequence
        if memo[i] != -1 { return memo[i]; } // memoization: return if subproblem already solved
        if colors[i as usize] == prev_color { // if curr color is same as prev color
            // memo[i] = Self::cal_min_cost(i-1, colors, needed_time, memo, colors[i as usize], prev_time.min(needed_time[i as usize]) + 1);
            return memo[i];
        } else { // if curr color diffs 
            memo[i] = Self::cal_min_cost(i-1, colors, needed_time, memo, colors[i as usize], needed_time[i as usize]);
            return memo[i];
        }
    }
}