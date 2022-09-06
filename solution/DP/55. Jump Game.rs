impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut jump_ind = 0;
        for cur in 0..nums.len() {
            if jump_ind < cur {
                return false;
            }
            jump_ind = std::cmp::max(jump_ind, cur + nums[cur] as usize);
        }
        return true;
    }
}

// greedy solution