#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2173: Maximum Strictly Increasing Cells in a Matrix
   * DP
   * Time: O(mnlog(mn)), Space: O(mn)
   *
   * @param mat
   * @return int
   */
  int maxIncreasingCells(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    map<int, vector<pair<int, int>>> g;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        g[mat[i][j]].emplace_back(i, j);  // same ele same group
      }
    }

    vector<int> row_max(m), col_max(n);
    for (auto& [_, pos] : g) {
      vector<int> mx;  // get max, update row_max / col_max
      for (auto& [i, j] : pos) {
        mx.push_back(max(row_max[i], col_max[j]) + 1);
      }
      for (int k = 0; k < pos.size(); k++) {
        auto& [i, j] = pos[k];
        row_max[i] = max(row_max[i], mx[k]);  // update row i max f
        col_max[j] = max(col_max[j], mx[k]);  // update col j max f
      }
    }
    return *max_element(row_max.begin(), row_max.end());
  }
};