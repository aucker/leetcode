impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut res = vec![0; nums.len()];
        let (mut le, mut ri, mut idx) = (0, nums.len() - 1, nums.len() - 1);
        while le <= ri {
            if nums[le].abs() > nums[ri].abs() {
                res[idx] = nums[le] * nums[le];
                le += 1;
            } else if nums[le].abs() <= nums[ri].abs() {
                res[idx] = nums[ri] * nums[ri];
                ri -= 1;
            }
            idx -= 1;
        }
        res
    }
}