use std::collections::BinaryHeap;

impl Solution {
    pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
        // let mut x: Vec<i32> = points.iter().map(|p| p[0]).collect();
        // x.sort();
        // let mut max = 0;
        // for i in 1..x.len() {
        //     max = max.max(x[i] - x[i - 1]);
        // }
        // max
        /// Sort is really slow here O(nlogn)
        
        // we use binary heap to store the elements
        let mut x: BinaryHeap<i32> = BinaryHeap::new();
        for p in points {
            x.push(p[0]);
        }

        let mut max = 0;
        let mut prev = x.pop().unwrap();
        while let Some(cur) = x.pop() {
            // max = max.max(cur - prev);
            // BinaryHeap is max heap, so we need to reverse the order
            max = max.max(prev - cur);
            prev = cur;
        }
        max
    }
}