use std::cmp::max;
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        /*
            1.不抢头，抢尾
            2.抢头，不抢尾
            3.不抢头，不抢尾 
        */
        let n = nums.len();
        if n == 0 {
            return 0;
        }
        if n == 1 {
            return nums[0];
        }
        let mut arr = nums.clone();
        let mut arr1 = &arr[1..n];
        let mut arr2 = &arr[0..n-1];
        let mut arr3 = &arr[1..n-1];

        max(max(Self::helper(arr1.to_vec()), Self::helper(arr2.to_vec())), Self::helper(arr3.to_vec()))

    }
    fn helper(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = vec![0; n];
        if n == 0 {
            return 0;
        }
        if n == 1 {
            return nums[0];
        }
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        let mut out = res[1];
        for i in 2..n {
            res[i as usize] = max(res[i as usize-1], res[i as usize-2] + nums[i as usize]); 
            out = max(res[i], out);
        }
        out
    }
}