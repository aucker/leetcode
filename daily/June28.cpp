#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2742: Painting the walls
   * Time & Space: O(n^2), DP: nums of state * time per state
   *
   * @param cost
   * @param time
   * @return int
   */
  int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<vector<int>> memo(n, vector<int>(n * 2 + 1, -1));
    auto dfs = [&](auto&& dfs, int i, int j) -> int {
      if (j > i) {  // all walls can be painted free
        return 0;
      }
      if (i < 0) {
        // j < 0
        return INT_MAX / 2;
      }
      int& res = memo[i][j + n];  // add offset
      if (res != -1) {            // calculated before
        return res;
      }
      return res = min(dfs(dfs, i - 1, j + time[i]) + cost[i],
                       dfs(dfs, i - 1, j - 1));
    };
    return dfs(dfs, n - 1, 0);
  }
};