#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 419: Battleships in board
   * Time: O(mn), Space: O(1)
   *
   * @param board
   * @return int
   */
  int countBattleships(vector<vector<int>>& board) {
    int ans = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 'X' && (j == 0 || board[i][j - 1] != 'X') &&
            (i == 0 || board[i - 1][j] != 'X')) {
          ans++;
        }
      }
    }
    return ans;
  }
};