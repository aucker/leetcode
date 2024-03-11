impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut res = vec![];
        let mut path = vec![];
        Self::dfs(&candidates, target, 0, &mut path, &mut res);
        res
    }
    
    fn dfs(candidates: &Vec<i32>, target: i32, start: usize, path: &mut Vec<i32>, res: &mut Vec<Vec<i32>>) {
        if target < 0 {
            return;
        }
        if target == 0 {
            res.push(path.clone());
            return;
        }
        for i in start..candidates.len() {
            path.push(candidates[i]);
            Self::dfs(candidates, target - candidates[i], i, path, res);
            path.pop();
        }
    }
}