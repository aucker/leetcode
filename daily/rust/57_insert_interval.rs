use std::cmp::{max, min}; // Add missing imports
impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let len = intervals.len();
        let mut ans: Vec<Vec<i32>> = vec![];
        let mut i = 0;

        // let (mut intervals, mut new_interval) = (intervals, new_interval);
        let mut new_interval = new_interval;

        // we insert the left side of the intervals into ans first, if any
        while (i < len && intervals[i][1] < new_interval[0]) {
            ans.push(intervals[i].clone());
            i += 1;
        }

        // we insert the intersection part, min the left, max the right
        while (i < len && intervals[i][0] <= new_interval[1]) {
            new_interval[0] = std::cmp::min(new_interval[0], intervals[i][0]);
            new_interval[1] = std::cmp::max(new_interval[1], intervals[i][1]);
            i += 1;
        }
        ans.push(new_interval);

        while (i < len) {
            ans.push(intervals[i].clone());
            i += 1;
        }

        ans
    }
}
