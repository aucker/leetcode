impl Solution {
    pub fn max_product_diffs(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let (mut min1, mut min2) = (i32::MAX, i32::MAX);
        let (mut max1, mut max2) = (i32::MIN, i32::MIN);
        for num in nums.iter() {
            if *num < min1 {
                min2 = min1;
                min1 = *num;
            } else if *num < min2 {
                min2 = *num;
            }

            if *num > max1 {
                max2 = max1;
                max1 = *num;
            } else if *num > max2  {
                max2 = *num;
            }
        }

        let mut res = 0;
        res = max1 * max2 - min1 * min2;
        res
    }
}