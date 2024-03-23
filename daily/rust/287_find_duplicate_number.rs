use std::collections::HashSet;
impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut seen = HashSet::new();
        for &num in nums {
            if seen.contains(&num) {
                return num;
            }
            seen.insert(num);
        }
        -1
    }
}