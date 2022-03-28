impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut n = nums.len();
        let mut fast = nums[nums[0] as usize];
        let mut slow = nums[0];
            
        while fast != slow {
            slow = nums[slow as usize];
            fast = nums[nums[fast as usize] as usize];
        }
        fast = 0;
        while fast != slow {
            fast = nums[fast as usize]; 
            slow = nums[slow as usize];
        }
        slow
    }
}

// use floyed cycle