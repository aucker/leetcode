impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n == 1 { return true; }
        if n < 1 { return false; }
        let mut m = n;
        while m % 2 == 0 && m > 1 {
            m = m / 2;
        }
        if m == 1 { return true; }
        false
    }
}
