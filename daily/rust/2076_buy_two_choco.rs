impl Solution {
    pub fn by_two_choco(prices: Vec<i32>, money: i32) -> i32 {
        let (mut min1, mut min2) = (std::i32::MAX, std::i32::MAX);
        for p in prices {
            if p < min1 {
                min2 = min1;
                min1 = p;
            } else if p < min2 {
                min2 = p;
            }
        }
        if min1 + min2 > money {
            return money;
        }
        money - min1 - min2
    }
}
