impl Solution {
    pub fn find_pivot(n: i32) -> i32 {
        // math
        // use sqrt to find the pivot
        let mut ans = 0;
        ans = (((n * n + n) / 2) as f64).sqrt() as i32;
        if ans * ans == (n * n + n) / 2 {
            return ans;
        }
        -1

        // traverse
        let mut sum_forward: i32 = (1 + n) * n / 2;
        let mut sum_backward: i32 = 0;
        let mut n: i32 = n;
        let mut ans: i32 = -1;

        while (n > 0) {
            sum_backward += n;

            if sum_backward == sum_forward {
                ans = n;
                break;
            }

            sum_forward -= n;
            n -= 1;
        }
        ans
    }
}