// https://leetcode.com/problems/find-all-duplicates-in-an-array/
use std::mem::swap;
impl Solution {

    pub fn find_duplicates(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut nums_cp = nums;
        // let mut nums_s: &[i32] = &nums_cp;
        let mut i = 0;
        while i < n {
            let mut curr_index = nums_cp[i] - 1;
            if nums_cp[i] != nums_cp[curr_index as usize] {
                nums_cp.swap(i, curr_index as usize);
                // println!("nums i is {}", nums_cp[i]);
            } else {
                i += 1;
            }
        }
        let mut ans:Vec<i32> = Vec::new();
        for i in 0..n as usize{
            if nums_cp[i] != i as i32+1 {
                ans.push(nums_cp[i]);
            }
        }
        ans
    }
}

// cost too much time, need to optimize
// with Runtime: 18ms, faster than 33.33%
// Memory Usage: 2.8MB, less than 50.00%