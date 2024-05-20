use std::collections::HashMap;

impl Solution {
    /// Time: O(n|\Sigma|), n: len(s), \Sigma: charset, 10 chars
    /// Space: O(min{n, 2^{|\Sigma|}}), the space that hash mapping
    pub fn longest_awesome(s: String) -> i32 {
        let mut prefix: HashMap<i32, i32> = HashMap::new();
        prefix.insert(0, -1);
        let mut ans = 0;
        let mut sequence = 0;
        for (i, ch) in s.chars().enumerate() {
            let digit = ch.to_digit(10).unwrap() as i32;
            sequence ^= (1 << digit);
            if let Some(&prev_index) = prefix.get(&sequence) {
                ans = ans.max(i as i32 - prev_index);
            } else {
                prefix.insert(sequence, i as i32);
            }

            for k in 0..10 {
                if let Some(&prev_index) = prefix.get(&(sequence ^ (1 << k))) {
                    ans = ans.max(i as i32 - prev_index);
                }
            }
        }

        ans
    }
}
