impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let len = arr.len();
        let mut count = 0;
        let mut prev = arr[0];
        let mut max = 0;
        for i in 0..len {
            if arr[i] == prev {
                count += 1;
            } else {
                count = 1;
                prev = arr[i];
            }
            if count > max {
                max = count;
            }
            if max > len / 4 {
                return prev;
            }
        }
        prev

    }
    
}