impl Solution {
    pub fn largest_odd_number(num: String) -> String {
        // for i in (0..num.len()).rev() {
        //     if (num.chars().nth(i).unwrap() as u8 - '0' as u8) % 2 != 0 {
        //         return num[..=i].to_string();
            // }
        // } // pivot is the rightmost odd character
        // "".to_string()
        /// the above use nth(i) with O(n) time and exceed time limit
        
        // let bytes = num.as_bytes();
        // let mut i = num.len();
        // while i > 0 && bytes[i - 1] % 2 == 0 {
        //     i -= 1;
        // }
        // num[..i].to_string()
        /// if converting a &str() to a String, into() can be slightly more efficient 'cause it doesn't need to traverse the string to find its length (since the length is stored in the &str)
        // but the difference is negligible

        let mid = match num.char_indices().rfind(|&(_, c)| (c as u8 - b'0') % 2 == 1) {
            Some((i, _)) => i + 1,
            None => 0,
        };
        let (s, _) = num.split_at(mid);
        s.into()
    }
}
