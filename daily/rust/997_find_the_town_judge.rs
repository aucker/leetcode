impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        // let mut inn: Vec<i32> = Vec::with_capacity(n as usize+1);
        // let mut out: Vec<i32> = Vec::with_capacity(n as usize+1);
        // // let mut out = vec![0; n+1];
        // // traverse trust and update in and out
        // for t in trust {
        //     out[t[0] as usize] += 1;
        //     inn[t[1] as usize] += 1;
        // }

        // for i in 1..=n {
        //     if inn[i] == n-1 && out[i] == 0 {
        //         return i as i32;
        //     }
        // }
        // -1

        if n == 1 { return n; }
        let mut counter = vec![0; (n + 1) as usize];
        trust.iter().for_each(|pair| {
            counter[pair[0] as usize] -= 1;
            counter[pair[1] as usize] += 1;
        });

        counter.iter().position(|&x| x == n - 1).map_or(-1, |x| x as i32)
    }
}
