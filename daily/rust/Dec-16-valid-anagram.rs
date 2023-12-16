impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        let mut buffers = vec![0; 26];
        let mut buffert = vec![0; 26];
        s.chars()
            .for_each(|c| buffers[c as usize - 'a' as usize] += 1);
        t.chars()
            .for_each(|c| buffert[c as usize - 'a' as usize] += 1);
        if buffers == buffert {
            return true;
        }
        false
    }
}
