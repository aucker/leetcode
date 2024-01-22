impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i = 0;
        let mut size = nums.len();
        while i < size {
            if nums[i] == val {
                nums[i] = nums[size - 1];
                size -= 1;
            } else {
                i += 1;
            }
        }
        size as i32
    }
}