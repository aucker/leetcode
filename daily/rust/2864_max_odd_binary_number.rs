impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let cnt1 = s.chars().filter(|&c| c == '1').count();
        let cnt0 = s.chars().filter(|&c| c == '0').count();

        let mut res = "1".repeat(cnt1 - 1) + &"0".repeat(cnt0) + "1";
        res
    }
}
        // for _ in 0..cnt1 - 1 {
        //     res.push('1');
        // }
        // for _ in 0..cnt0 {
        //     res.push('0');
        // }
        // res.push('1');
        // res
    // }
// }