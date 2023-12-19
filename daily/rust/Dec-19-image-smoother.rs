impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut img = img;
        let row = img.len();
        let col = img[0].len();
        let mut res = vec![vec![0; col]; row];

        // for i in 0..row {
        //     for j in 0..col {
        //         let mut sum = 0;
        //         let mut count = 0;
        //         for x in i.saturating_sub(1)..=i + 1 {
        //             for y in j.saturating_sub(1)..=j + 1 {
        //                 if x < row && y < col {
        //                     sum += img[x][y];
        //                     count += 1;
        //                 }
        //             }
        //         }
        //         res[i][j] = sum / count;
        //     }
        // }
        for i in 0..row {
            for j in 0..col {
                let (mut sum, mut count) = (0, 0);
                
                for x in (max(i as i32 - 1, 0) as usize)..(min(i as i32+2, row as i32) as usize) {
                    for y in (max(j as i32 - 1, 0) as usize)..(min(j as i32+2, col as i32) as usize) {
                        sum += img[x][y];
                        count += 1;
                    }
                }
                res[i][j] = sum / count;
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    
    use super::*;

    #[test]
    fn test1() {
        let img = vec![vec![1,1,1],vec![1,0,1],vec![1,1,1]];
        let res = vec![vec![0,0,0],vec![0,0,0],vec![0,0,0]];
        assert_eq!(Solution::image_smoother(img), res);
    }

    #[test]
    fn test2() {
        let img = vec![vec![2,3,4],vec![5,6,7],vec![8,9,10],vec![11,12,13],vec![14,15,16]];
        let res = vec![vec![4,4,5],vec![5,6,6],vec![8,9,9],vec![11,12,12],vec![13,13,14]];
        assert_eq!(Solution::image_smoother(img), res);
    }

    #[test]
    fn test3() {
        let img = vec![vec![2,3,4],vec![5,6,7],vec![8,9,10],vec![11,12,13],vec![14,15,16]];
        let res = vec![vec![4,4,5],vec![5,6,6],vec![8,9,9],vec![11,12,12],vec![13,13,14]];
        assert_eq!(Solution::image_smoother(img), res);
    }
    
}

/// I use the most dumb way to solve this problem
/// Just consider every situation, there are many corner cases
// if row == 1 && col == 1 {
//     return img;
// }

// if row == 1 {
//     if col == 2 {
//         res[0][0] = (img[0][0] + img[0][1]) / 2;
//         res[0][1] = (img[0][0] + img[0][1]) / 2;
//     }
//     else {
//         res[0][0] = (img[0][0] + img[0][1]) / 2;
//         res[0][col - 1] = (img[0][col - 1] + img[0][col - 2]) / 2;
//         for i in 1..col - 1 {
//             res[0][i] = (img[0][i - 1] + img[0][i] + img[0][i + 1]) / 3;
//         }
//     }
// }

// if col == 1 {
//     if row == 2 {
//         res[0][0] = (img[0][0] + img[1][0]) / 2;
//         res[1][0] = (img[0][0] + img[1][0]) / 2;
//     }
//     else {
//         res[0][0] = (img[0][0] + img[1][0]) / 2;
//         res[row - 1][0] = (img[row - 1][0] + img[row - 2][0]) / 2;
//         for i in 1..row - 1 {
//             res[i][0] = (img[i - 1][0] + img[i][0] + img[i + 1][0]) / 3;
//         }
//     }
// }

// if row > 1 && col > 1 {
//     res[0][0] = (img[0][0] + img[0][1] + img[1][0] + img[1][1]) / 4;
//     res[0][col - 1] = (img[0][col - 1] + img[0][col - 2] + img[1][col - 1] + img[1][col - 2]) / 4;
//     res[row - 1][0] = (img[row - 1][0] + img[row - 1][1] + img[row - 2][0] + img[row - 2][1]) / 4;
//     res[row - 1][col - 1] = (img[row - 1][col - 1] + img[row - 1][col - 2] + img[row - 2][col - 1] + img[row - 2][col - 2]) / 4;

//     for i in 1..row - 1 {
//         res[i][0] = (img[i - 1][0] + img[i - 1][1] + img[i][0] + img[i][1] + img[i + 1][0] + img[i + 1][1]) / 6;
//         res[i][col - 1] = (img[i - 1][col - 1] + img[i - 1][col - 2] + img[i][col - 1] + img[i][col - 2] + img[i + 1][col - 1] + img[i + 1][col - 2]) / 6;
//     }

//     for i in 1..col - 1 {
//         res[0][i] = (img[0][i - 1] + img[0][i] + img[0][i + 1] + img[1][i - 1] + img[1][i] + img[1][i + 1]) / 6;
//         res[row - 1][i] = (img[row - 1][i - 1] + img[row - 1][i] + img[row - 1][i + 1] + img[row - 2][i - 1] + img[row - 2][i] + img[row - 2][i + 1]) / 6;
//     }
    
//     for i in 1..row - 1 {
//         for j in 1..col - 1 {
//             res[i][j] = (img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1] + img[i][j - 1] + img[i][j] + img[i][j + 1] + img[i + 1][j - 1] + img[i + 1][j] + img[i + 1][j + 1]) / 9;
//         }
//     }
// }