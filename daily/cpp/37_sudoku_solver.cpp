#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        backtrack(board, i, j);
      }
    }
    return;
  }

 private:
  bool backtrack(vector<vector<char>>& board, int i, int j) {
    int m = 9, n = 9;

    if (j == m) {
      // go to the last col, go to next row
      return backtrack(board, i + 1, 0);
    }

    // if we encounter a number, skip and contineue
    if (board[i][j] != '.') {
      return backtrack(board, i, j + 1);
    }

    for (char ch = '1'; ch <= '9'; ++ch) {
      // invalid number
      if (!isValid(board, i, j, ch)) {
        continue;
      }
      // selection
      board[i][j] = ch;
      // next position, if we find a valid case, just return true
      if (backtrack(board, i, j + 1)) {
        return true;
      }
      // recover the ch
      board[i][j] = '.';
    }
    return false;
  }

  bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; ++i) {
      // check repeatition in row
      if (board[r][i] == ch) return false;
      // check repeatition in col
      if (board[i][c] == ch) return false;
      // check subbox 3 x 3 repeat
      if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return false;
    }
    return true;
  }
};