#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2923: Find the Champion
   * this solution time complexity is based on two layer of loops
   * So, really slow
   * @param grid
   * @return int
   */
  int findChampion(vector<vector<int>>& grid) {
    int sz = grid.size();
    // int the bool matrix, if grid[i][j] == 1 && i != j, i win
    unordered_map<int, int> mp;
    using pair_type = decltype(mp)::value_type;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        if (i == j) {
          // nothing
        }
        if (grid[i][j] == 1) {
          mp[i]++;
          mp[j]--;
        } else {
          mp[i]--;
          mp[j]++;
        }
      }
    }
    auto best = std::max_element(
        mp.begin(), mp.end(), [](const pair_type& lhs, const pair_type& rhs) {
          return lhs.second < rhs.second;
        });
    return best->first;
  }

  /// @brief Every time we update the result, this is fast
  /// @param grid
  /// @return
  int findChampionOP(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 1; i < grid.size(); i++) {
      if (grid[i][ans]) {
        ans = i;
      }
    }
    return ans;
  }
};