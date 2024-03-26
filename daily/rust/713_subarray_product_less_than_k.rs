impl Solution {
    pub fn num_subarray_product_lt_k(nums: Vec<i32>, k: i32) -> i32 {
        if k == 0 {return 0;}
        let (mut cnt, mut pro) = (0, 1);
        let mut l  = 0;
        for r in 0..nums.len() {
            pro *= nums[r];
            while l <= r && pro >= k {
                pro /= nums[l];
                l+=1;
            }
            cnt += r - l + 1;
        }
        cnt as i32
    }
}