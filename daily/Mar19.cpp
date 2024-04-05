#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief check if a sukodu is valid, which means, the same row, col, and diag
   * should not be same, and every subbox is no identical numbers
   *
   * @param board
   * @return true
   * @return false
   */
  bool isValidSukodu(vector<vector<char>>& board) {
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int subs[3][3][9] = {0};

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c != '.') {
          int idx = c - '0' - 1;
          rows[i][idx]++;
          cols[j][idx]++;
          subs[i / 3][j / 3][idx]++;
          if (rows[i][idx] > 1 || cols[j][idx] > 1 ||
              subs[i / 3][j / 3][idx] > 1) {
            return false;
          }
        }
      }
    }

    return true;
  }

  /**
   * @brief N Queen problem
   * use Recursive, that is backtrack
   *
   * @param n
   * @return vector<vector<string>>
   */
  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return ans;
  }

 private:
  vector<vector<string>> ans;
  /**
   * @brief this is helper function: backtrack
   *
   * @param board
   * @param row
   */
  void backtrack(vector<string>& board, int row) {
    // end case
    if (row == board.size()) {
      ans.emplace_back(board);
      return;
    }

    int n = board[row].size();
    for (int col = 0; col < n; ++col) {
      // remove inValid
      if (!isValid(board, row, col)) {
        continue;
      }

      // select
      board[row][col] = 'Q';
      // next decision
      backtrack(board, row + 1);
      // undo
      board[row][col] = '.';
    }
  }

  /**
   * @brief check the previous part is valid or not, we check the curr part, and
   * top left part and top right part to make sure there is only 1 Q for every
   * row and col of visited area
   *
   * @param board
   * @param row
   * @param col
   * @return true
   * @return false
   */
  bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // check conflict
    for (int i = 0; i < row; ++i) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }

    // check top right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    // check top left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
};