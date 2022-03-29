// https://leetcode.com/problems/spiral-matrix/
impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let (mut sr, mut er, mut sc, mut ec) = (0, matrix.len() as i32-1, 0, matrix[0].len() as i32-1);
        // sr: starting row
        // er: seding row
        // sc: starting column
        // ec: ending column
        let mut ans: Vec<i32> = Vec::new();
        // println!("sr = {}, er = {}, sc = {}, ec = {}", sr, er, sc, ec);
        // println!("matrix = {:?}", matrix[sr][sc]);
        // ans.push(matrix[sr][sc]);
        // println!("ans = {:?}", ans);
        
        while(sr<=er && sc<=ec) {
            for i in sc..=ec {
                ans.push(matrix[sr as usize][i as usize]);
            }
            // upper row
            
            for i in (sr+1)..=er {
                ans.push(matrix[i as usize][ec as usize]);
            }
            // right column
            
            if sr < er {
                for i in (sc..=(ec-1)).rev() {
                    ans.push(matrix[er as usize][i as usize]);
                }
            }
            
            if sc < ec {
                for i in ((sr+1)..=(er-1)).rev() {
                    ans.push(matrix[i as usize][sc as usize]);
                }
            }
            sr += 1;
            er -= 1;
            sc += 1;
            ec -= 1;
        }
        ans
    }
}
// Don't use `usize`!!!!!!
// Runtime: 0 ms, faster than 100.00% of Rust online submissions for Spiral Matrix.
// Memory Usage: 2 MB, less than 79.55% of Rust online submissions for Spiral Matrix.
