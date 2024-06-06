#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC:3067: Count pairs of connectable servers in a
   * Weighted Tree Network
   * Time: O(N^2), Space: O(n)
   *
   * @param edges
   * @param signalSpeed
   * @return vector<int>
   */
  vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                             int signalSpeed) {
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> g(n);
    for (auto& e : edges) {
      int x = e[0], y = e[1], wt = e[2];
      g[x].push_back({y, wt});
      g[y].push_back({x, wt});
    }

    function<int(int, int, int)> dfs = [&](int x, int fa, int sum) -> int {
      int cnt = sum % signalSpeed == 0;
      for (auto& [y, wt] : g[x]) {
        if (y != fa) {
          cnt += dfs(y, x, sum + wt);
        }
      }
      return cnt;
    };

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (auto& [y, wt] : g[i]) {
        int cnt = dfs(y, i, wt);
        ans[i] += cnt * sum;
        sum += cnt;
      }
    }
    return ans;
  }
};