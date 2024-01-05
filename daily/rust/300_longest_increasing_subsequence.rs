impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut dp = vec![1; nums.len()];
        let mut max = 0;
        for i in 0..nums.len() {
            for j in 0..i {
                if nums[i] > nums[j] {
                    dp[i] = dp[i].max(dp[j] + 1);
                }
            }
        }
        max = dp.iter().max().unwrap_or(&0).clone();
        max
    }
}