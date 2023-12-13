impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        let row = mat.len();
        let col = mat[0].len();
        let mut mark = 0;
        for i in 0..row {
            for j in 0..col {
                if mat[i][j] == 1 {
                    mark = 1;
                    for k in 0..row {
                        if mat[k][j] == 1 && k != i {
                            mark = 0;
                            break;
                        }
                    }
                    for k in 0..col {
                        if mat[i][k] == 1 && k != j {
                            mark = 0;
                            break;
                        }
                    }
                    res += mark;
                }
            }
        }
        res
    }
}