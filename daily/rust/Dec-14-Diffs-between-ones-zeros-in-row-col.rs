impl Solution {
    pub fn ones_minus_zeros(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let row = grid.len();
        let col = grid[0].len();
        let mut res = vec![vec![0; col]; row];
        let mut row_one = vec![0i32; col];
        let mut col_one = vec![0i32; row];
        for i in 0..row {
            for j in 0..col {
                if grid[i][j] == 1 {
                    row_one[j] += 1;
                    col_one[i] += 1;
                }
            }
        }

        for i in 0..row {
            for j in 0..col {
                res[i][j] = row_one[j] + col_one[i] - (row as i32 - row_one[j]) - (col as i32 - col_one[i]);
            }
        }
        res
    }
}
