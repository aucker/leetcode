impl Solution {
    fn max_product(nums: &mut Vec<i32>) -> i32 {
        let mut max1 = i32::MIN;
        let mut max2 = i32::MIN;
        // for &num in nums.iter() {
        //     if num >= max1 {
        //         max2 = max1;
        //         max1 = num;
        //     } else if num > max2 {
        //         max2 = num;
        //     }
        // }
        nums.iter().for_each(|&num| {
            if num >= max1 {
                max2 = max1;
                max1 = num;
            } else if num > max2 {
                max2 = num;
            }
        });
        (max1 - 1) * (max2 - 1)
    }
}
