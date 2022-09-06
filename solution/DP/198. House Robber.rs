use std::cmp::max;
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 0 {
            return 0;
        }
        if n == 1 {
            return nums[0];
        }
        let mut res = vec![0; n];
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for i in 2..n {
            res[i as usize] = max(res[i as usize-1], res[i as usize-2] + nums[i as usize]);
        }
        res[n as usize-1]
    }
}