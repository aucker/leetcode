impl Solution {
    pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
        let mut right_shift = 0;
        let (mut leftt, mut rightt) = (left, right);
        while leftt != rightt {
            leftt = leftt >> 1;
            rightt = rightt >> 1;
            right_shift += 1;
        }

        leftt << right_shift
    }
}
