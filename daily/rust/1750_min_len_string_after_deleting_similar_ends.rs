impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut s = s.as_bytes();
        let (mut le, mut ri) = (0, s.len() - 1);
        while le < ri && s[le] == s[ri] {
            let mut c = s[le];
            while le <= ri && s[le] == c {
                le += 1;
            }
            while le <= ri && s[ri] == c {
                ri -= 1;
            }
        }
        (ri - le + 1) as i32
    }
}