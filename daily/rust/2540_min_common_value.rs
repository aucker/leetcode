impl Solution {
    pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        // let mut common = std::collections::HashSet::new();
        // for n in nums1 {
        //     common.insert(n);
        // }
        // let mut min = std::i32::MAX;
        // let mut flag = 0;
        // for n in nums2 {
        //     if common.contains(&n) {
        //         min = std::cmp::min(min, n);
        //         flag += 1;
        //     }
        // }
        // if flag == 0 {
        //     return -1;
        // }
        // min

        let mut res = -1;
        let (mut sz1, mut sz2) = (nums1.len(), nums2.len());
        let (mut i, mut j) = (0, 0);
        let (mut nums1, mut nums2) = (nums1, nums2);
        while (i < sz1) && (j < sz2) {
            if nums1[i] == nums2[j] {
                res = nums1[i];
                break;
            } else if nums1[i] < nums2[j] {
                i += 1;
            } else {
                j += 1;
            }
        }
        res
    }
}