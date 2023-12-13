impl Solution {
    // pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        // let mut res = 0;
        // let row = mat.len();
        // let col = mat[0].len();
        // let mut mark = 0;
        // for i in 0..row {
        //     for j in 0..col {
        //         if mat[i][j] == 1 {
        //             mark = 1;
        //             for k in 0..row {
        //                 if mat[k][j] == 1 && k != i {
        //                     mark = 0;
        //                     break;
        //                 }
        //             }
        //             for k in 0..col {
        //                 if mat[i][k] == 1 && k != j {
        //                     mark = 0;
        //                     break;
        //                 }
        //             }
        //             res += mark;
        //         }
        //     }
        // }
        // res

        /// Version 2
        // let mut res = 0;
        // for i in 0..mat.len() {
        //     let mut index = Self::check_row(&mat, i);
        //     if (index >= 0 && Self::check_col(&mat, i, index)) {
        //         res += 1;
        //     }
        // }
        // res
    // }

    // fn check_row(mat: &Vec<Vec<i32>>, i: usize) -> i32 {
    //     let mut index = -1;
    //     for j in 0..mat[0].len() {
    //         if mat[i][j] == 1 {
    //             if index >= 0 {
    //                 return -1;
    //             } else {
    //                 index = j as i32;
    //             }
    //         }
    //     }
    //     index
    // }

    // fn check_col(mat: &Vec<Vec<i32>>, i: usize, index: i32) -> bool {
    //     for j in 0..mat.len() {
    //         if mat[j][index as usize] == 1 && j != i {
    //             return false;
    //         }
    //     }
    //     true
    // }

    /// Version 3
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let row = mat.len();
        let col = mat[0].len();
        let mut rs = vec![0; row];
        let mut cs = vec![0; col];
        for i in 0..row {
            for j in 0..col {
                rs[i] += mat[i][j];
                cs[j] += mat[i][j];
            }
        }
        let mut res = 0;
        for i in 0..row {
            for j in 0..col {
                if mat[i][j] == 1 && rs[i] <= 1 && cs[j] <= 1 {
                    res += 1;
                }
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use std::vec;

    use super::*;
    
    #[test]
    fn test_1() {
        assert_eq!(Solution::num_special(vec![vec![1,0,0],vec![0,0,1],vec![1,0,0]]), 1);
    }

    #[test]
    fn test_2() {
        assert_eq!(Solution::num_special(vec![vec![1,0,0],vec![0,1,0],vec![0,0,1]]), 1);
    }

    #[test]
    fn test_3() {
        assert_eq!(
            Solution::num_special(vec![
                vec![0,0,0,1],
                vec![1,0,0,0],
                vec![0,1,1,0],
                vec![0,0,0,0]
            ]),
            2
        );
    }

    #[test]
    fn test_4() {
        assert_eq!(
            Solution::num_special(vec![
                vec![0,0,0,0,0],
                vec![1,0,0,0,0],
                vec![0,1,0,0,0],
                vec![0,0,1,0,0],
                vec![0,0,0,1,1]
            ]),
            3
        );
    }

    #[test]
    fn test_5() {
        assert_eq!(
            Solution::num_special(vec![
                vec![0,0,0,0,0,1,0,0],
                vec![0,0,0,0,1,0,0,1],
                vec![0,0,0,0,1,0,0,0],
                vec![1,0,0,0,1,0,0,0],
                vec![0,0,1,1,0,0,0,0]
            ]),
            1
        );
    }

    #[test]
    fn test_6() {
        assert_eq!(
            Solution::num_special(vec![vec![0,0],vec![0,0],vec![1,0]]),
            1
        );
    }
}