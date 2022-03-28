impl Solution {
    pub fn contains_duplicate(mut nums: Vec<i32>) -> bool {
        // let mut n = nums.len();
        // for i in 0..(n-1) {
        //     for mut j in (i+1)..n {
        //         if nums[i] == nums[j] {
        //             return true;
        //         }
        //     }
        // }
        // false
        
        
        // let mut f = nums.sort();
        // for i in 1..nums.len() {
        //     if nums[i] == nums[i-1] {
        //         return true;
        //     }
        // }
        // false
        
        use std::collections::HashSet;
        
        let mut distinct:HashSet<i32> = HashSet::new();
        for num in nums.iter() {
            if distinct.contains(num) {
                return true
            } 
            distinct.insert(*num);
        }
        false
        
    }

}
//1. just like the C++ use loop solution, with O(n^2)


//2. we sort the nums first, then we find through the vec; 
// for rust, if a vec doesn't implement the MUT, then it cannot be changed; the TIME complexity is O(nlogn)

//3. we use a hashtable to store the numbers that occure in the nums vector;
// then, everytime we just compare one time; 
// the TIME complexity is O(N)