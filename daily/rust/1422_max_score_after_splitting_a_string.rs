impl Solution {
    pub fn max_score(s: String) -> i32 {
        let mut res = 0;
        let mut zeros = 0;
        let mut ones = s.chars().filter(|&c| c == '1').count();

        for c in s.chars().take(s.len() - 1) {
            if c == '0' {
                zeros += 1;
            } else {
                ones -= 1;
            }
            res = res.max(zeros + ones);
        }
        res as i32
    }
}