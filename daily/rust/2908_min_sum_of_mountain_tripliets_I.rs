impl Solution {
    pub fn minimum_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut nums = nums;
        if n < 3 {
            return -1;
        }

        let mut suf = vec![0; n];
        suf[n - 1] = nums[n - 1];
        for i in (2..(n - 1)).rev() {
            // suf[i] = std::cmp::min(suf[i+1], nums[i]);
            suf[i] = suf[i + 1].min(nums[i]);
        }

        let mut ans = i32::MAX;
        let mut pre = nums[0]; // min prefix

        for j in 1..(n - 1) {
            if (pre < nums[j] && nums[j] > suf[j + 1]) {
                ans = ans.min(pre + nums[j] + suf[j + 1]);
            }
            pre = pre.min(nums[j]);
        }

        if ans == i32::MAX {
            -1
        } else {
            ans
        }
    }
}
