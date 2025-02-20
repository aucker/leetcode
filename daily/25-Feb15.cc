#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief 1706: Where will the ball fall
   * Time: O(row * col), Space: O(1)
   *
   * @param grid
   * @return vector<int>
   */
  vector<int> findBall(vector<vector<int>>& grid) {
    int n = grid[0].size();
    vector<int> ans(n);
    for (int j = 0; j < n; j++) {
      int cur_col = j;
      for (auto& row : grid) {
        int d = row[cur_col];
        cur_col += d;

        if (cur_col < 0 || cur_col == n || row[cur_col] != d) {
          cur_col = -1;
          break;
        }
      }
      ans[j] = cur_col;
    }
    return ans;
  }
};
