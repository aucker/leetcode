#include <iostream>
using namespace std;

class Solution {
 public:
 /**
  * @brief LC3193: count the number of inversions
  * DP: Time: O(N * M * min(N, M)), Space: O(N * M)
  *
  * @param n
  * @param requirements
  * @return int
  */
  int numberOfPermutations(int n, vector<vector<int>>& requirements) {
    vector<int> req(n, -1);
    req[0] = 0;
    for (auto& p : requirements) {
      req[p[0]] = p[1];
    }
    if (req[0]) {
      return 0;
    }

    int m = ranges::max(req);
    vector<vector<int>> memo(n, vector<int>(m + 1, -1));  // not counted
    auto dfs = [&](auto&& dfs, int i, int j) -> int {
      if (i == 0) {
        return 1;
      }

      int& res = memo[i][j];
      if (res != -1) {
        return res;
      }
      res = 0;

      if (int r = req[i - 1]; r >= 0) {
        if (j >= r && j - i <= r) {
          res = dfs(dfs, i - 1, r);
        }
      } else {
        for (int k = 0; k <= min(i, j); k++) {
          res = (res + dfs(dfs, i - 1, j - k)) % MOD;
        }
      }
      return res;
    };

    return dfs(dfs, n - 1, req[n - 1]);
  }

 private:
  const int MOD = 1'000'000'007;
};
