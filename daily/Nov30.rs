impl Solution {
    pub fn can_alice_win(nums: Vec<i32>) -> bool {
        let (mut oneSum, mut twoSum) = (0, 0);
        for num in &nums {
            if *num > 0 && *num < 10 {
                oneSum += *num;
            } else {
                twoSum += *num;
            }
        }
        if oneSum != twoSum {
            return true;
        }
        false
    }
}
