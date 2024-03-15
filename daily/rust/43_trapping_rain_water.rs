impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        let (mut le, mut ri) = (0, n - 1);
        let (mut maxle, mut maxri) = (0, 0);
        let mut ans = 0;
        while le < ri {
            if height[le] < height[ri] {
                if height[le] < maxle {
                    maxle = height[le];
                } else {
                    ans += (maxle - height[le]);
                    le += 1;
                }
            } else {
                if height[ri] < maxri {
                    maxri = height[ri];
                } else {
                    ans += (maxri - height[ri]);
                    ri -= 1;
                }
            }
        }
        ans
    }
}
