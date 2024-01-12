impl Solution {
    pub fn halves_are_alike(s: String) -> bool {
        let mut count = 0;
        let mut i = 0;
        let mut j = s.len() - 1;
        let vowels = ['a', 'e', 'i', 'o', 'u'];
        while i < j {
            if vowels.contains(&s.chars().nth(i).unwrap().to_ascii_lowercase()) {
                count += 1;
            }
            if vowels.contains(&s.chars().nth(j).unwrap().to_ascii_lowercase()) {
                count -= 1;
            }
            i += 1;
            j -= 1;
        }
        count == 0
    }
}