#include <bits/stdc++.h>
using namespace std;

class NQueen {
 private:
  vector<vector<string>> ans;

 public:
  vector<vector<string>> solveNQueens(int n) {
    // '.' is empty, 'Q' is queen
    // init board with string vector
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return ans;
  }

  // Path: all rows that are smaller than row has queen
  // select from: 'row' row every col is option to place queen
  // end: row is equal or greater than last row of board, which is full
  void backtrack(vector<string>& board, int row) {
    // when to end
    if (row == board.size()) {
      ans.push_back(board);
      return;
    }

    int n = board[0].size();
    for (int col = 0; col < n; ++col) {
      // remove invalid option
      if (!isValid(board, row, col)) {
        continue;
      }
      // make selection
      board[row][col] = 'Q';
      // go to next decision
      backtrack(board, row + 1);
      // recover
      board[row][col] = '.';
    }
  }

  bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // check the queens are in conflict
    for (int i = 0; i < row; ++i) {
      // curr is 'Q', cant put queen, invalid
      if (board[i][col] == 'Q') return false;
    }

    // check if top right is valid
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[i][j] == 'Q') return false;
    }

    // check if top left valid
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q') return false;
    }

    return true;
  }
};

class NQueenOP {
 public:
  vector<vector<string>> solveNQueen(int n) {
    vector<vector<string>> ans;
    vector<int> col(n), on_path(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
    function<void(int)> dfs = [&](int r) {
      // we traverse the last row, this is end
      if (r == n) {
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
          board[i] = string(col[i], '.') + 'Q' + string(n - 1 - col[i], '.');
        }
        ans.emplace_back(board);
        return;
      }

      // or, we just traverse every row & col
      for (int c = 0; c < n; c++) {
        int rc = r - c + n - 1;
        if (!on_path[c] && !diag1[r + c] && !diag2[rc]) {
          col[r] = c;
          // try to place at pos
          on_path[c] = diag1[r + c] = diag2[rc] = true;
          // go to next row by backtrack
          dfs(r + 1);
          // recover this by undo
          on_path[c] = diag1[r + c] = diag2[rc] = false;
        }
      }
    };
    // we solve this from first row : row 0
    dfs(0);
    return ans;
  }
};

class Sudoku {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        backtrack(board, i, j);
      }
    }
  }

  void backtrack(vector<vector<char>>& board, int i, int j) {
    int row = 9, col = 9;
    if (j == col) {
      // go to last col, need to go to next row
      backtrack(board, i + 1, 0);
      return;
    }

    // if this pos has number, skip
    if (board[i][j] != '.') {
      backtrack(board, i, j + 1);
      return;
    }

    for (char ch = '1'; ch <= '9'; ++ch) {
      // if not valid, skip
      if (!isValid(board, i, j, ch)) {
        continue;
      }
      // make selection
      board[i][j] = ch;
      // go to next pos
      backtrack(board, i, j + 1);
      // recorver
      board[i][j] = '.';
    }
  }

  bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; ++i) {
      // check repeat in row
      if (board[r][i] == ch) return false;
      // check repeat in col
      if (board[i][c] == ch) return false;
      // check subbox
      if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return false;
    }
    return true;
  }
};