impl Solution {
    pub fn minimum_refill(plants: Vec<i32>, capacity_a: i32, capacity_b: i32) -> i32 {
        let (mut vala, mut valb) = (capacity_a, capacity_b);
        let n = plants.len();
        let mut posa: usize = 0;
        let mut posb: usize = n-1;
        let mut res = 0;
        while posa < posb {
            if vala < plants[posa] {
                res += 1;
                vala = capacity_a - plants[posa];
            } else {
                vala -= plants[posa];
            }
            posa += 1;
            if valb < plants[posb] {
                res += 1;
                valb = capacity_b - plants[posb];
            } else {
                valb -= plants[posb];
            }
            posb -= 1;
        }
        if posa == posb {
            if vala >= valb && vala < plants[posa] {
                res += 1;
            }
            if vala < valb && valb < plants[posb] {
                res += 1;
            }
        }
        return res;
    }
}