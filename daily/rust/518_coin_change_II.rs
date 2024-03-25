impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let total = amount as usize;
        let mut dp: Vec<i32> = vec![0; total + 1];
        dp[0] = 1;
        for &coin in coins.iter() {
            let coin_val = coin as usize;
            for i in coin_val..=total {
                dp[i] += dp[i - coin_val];
            }
        }
        dp[total]
    }
}
