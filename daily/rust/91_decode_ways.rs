impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let mut dp = vec![0; s.len() + 1];
        dp[0] = 1;
        dp[1] = if s.chars().nth(0).unwrap() == '0' { 0 } else { 1 };

        for i in 2..=s.len() {
            let one = s[i - 1..i].parse::<i32>().unwrap();
            let two = s[i - 2..i].parse::<i32>().unwrap();

            if one >= 1 {
                dp[i] += dp[i - 1];
            }
            if two >= 10 && two <= 26 {
                dp[i] += dp[i - 2];
            }
        }
        dp[s.len()]
    }
}