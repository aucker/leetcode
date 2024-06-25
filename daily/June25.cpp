#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2732: Good Subset of Matrix [H]
   * Time:
   * Space:
   *
   * @param grid
   * @return vector<int>
   */
  vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
    vector<int> a[1 << 5];
    vector<int> ans;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      int s = 0;
      for (auto c : grid[i]) {
        s = (s << 1) + c;
      }
      if (s == 0) {
        ans.push_back(i);
        return ans;
      }
      a[s].push_back(i);
    }
    for (int i = 0; i < (1 << n); i++) {
      if (a[i].size() == 0) {
        continue;
      }
      for (int j = i + 1; j < (1 << n); j++) {
        if (a[j].size() == 0) {
          continue;
        }
        if ((i & j) == 0) {
          ans.push_back(a[i][0]);
          ans.push_back(a[j][0]);
          sort(ans.begin(), ans.end());
          return ans;
        }
      }
    }
    return ans;
  }
};