impl Solution {
    pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        /// This is fast, but not fast enough
        /// 
        // let mut nums = nums;
        // nums.sort();
        // let mut res = vec![];
        // for i in (0..=nums.len() - 3).step_by(3) {
        //     if nums[i + 2] - nums[i] > k {
        //         return vec![];
        //     } 
        //     res.push(vec![nums[i], nums[i + 1], nums[i + 2]]);
        // } 
        // res

        /// The following solution is way more faster
        /// 
        // nums.sort_unstable();
        // match nums.chunks(3).map(|c| c[2] - c[0]).any(|d| d > k) {
        //     true => vec![],
        //     false => nums.chunks(3).map(|c| c.to_vec()).collect(),
        // }

        nums.sort_unstable();
        if nums.chunks(3).map(|c| c[2] - c[0]).max().unwrap() > k {
            return vec![];
        }
        nums.chunks(3).map(|c| c.to_vec()).collect()
    }
}