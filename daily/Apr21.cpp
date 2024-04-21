#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Enumeration of which one to choose
   *
   * @param k
   * @param n
   * @return vector<vector<int>>
   */
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int)> dfs = [&](int i, int t) {
      int d = k - path.size();  // left number
      if (t < 0 || t > (i * 2 - d + 1) * d / 2) {
        // prune
        return;
      }
      if (d == 0) {  // find a valid path
        ans.emplace_back(path);
        return;
      }
      for (int j = i; j >= d; j--) {
        path.push_back(j);
        dfs(j - 1, t - j);
        path.pop_back();
      }
    };
    dfs(9, n);
    return ans;
  }

  vector<vector<int>> combinationSum3Op(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;
    function<void(int, int)> dfs = [&](int i, int t) {
      int d = k - path.size();                   // left to choose
      if (t < 0 || t > (i * 2 - d + 1) * d / 2)  // prune
        return;
      if (d == 0) {  // find a valid combination
        ans.emplace_back(path);
        return;
      }

      // not i
      if (i > d) {
        dfs(i - 1, t);
      }

      // i
      path.push_back(i);
      dfs(i - 1, t - i);
      path.pop_back();
    };
    dfs(9, n);
    return ans;
  }
};