#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int rows[9][9];
    int cols[9][9];
    int subbox[3][3][9];

    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    memset(subbox, 0, sizeof(subbox));

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c != '.') {
          int index = c - '0' - 1;
          rows[i][index]++;
          cols[j][index]++;
          subbox[i / 3][j / 3][index]++;
          if (rows[i][index] > 1 || cols[i][index] > 1 ||
              subbox[i / 3][j / 3][index] > 1) {
            return false;
          }
        }
      }
    }
    return true;
  }
};