pub struct Solution{}
// https://leetcode.com/problems/set-matrix-zeroes/ . 73
impl Solution {
    pub fn set_zeros(matrix: &mut Vec<Vec<i32>>) {
        let (Row, Col) = (matrix.len(), matrix[0].len());
        // Record every `0` row and col, then let them be 0
        let mut row: Vec<i32> = Vec::new();
        let mut col: Vec<i32> = Vec::new();
        for i in 0..Row {
            for j in 0..Col {
                if matrix[i][j] == 0 {
                    row.push(i as i32);
                    col.push(j as i32);
                }
            }
        }
        for i in 0..row.len() {
            for j in 0..Col{
                matrix[row[i] as usize][j] = 0;
            }
        }
        for j in 0..col.len() {
            for i in 0..Row {
                matrix[i][col[j] as usize] = 0;
            }
        }

    }
}

#[cfg(test)]
mod tests {
    use std::result;

    use super::*;
    #[test]
    fn it_works() {
        // let result = 2 + 2;
        // assert_eq!(result, 4);
        let matrix = [[1,1,1],[1,0,1],[1,1,1]];
        let result = [[1,0,1],[0,0,0],[1,0,1]];
        // assert_eq!(Solution::set_zeros(matrix), result);
    }
}
