impl Solution {
    pub fn find_winners(matches: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut loss_count = HashMap::new();
        for m in matches {
            loss_count.entry(m[0]).or_insert(0);
            *loss_count.entry(m[1]).or_insert(0) += 1;
        }

        let mut ans = vec![vec![], vec![]];
        for (player, cnt) in loss_count {
            if cnt < 2 {
                ans[cnt as usize].push(player);
            }
        }

        ans[0].sort_unstable();
        ans[1].sort_unstable();
        ans
    }
}