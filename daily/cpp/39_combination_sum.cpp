#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /* A typical backtrack solution */
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(candidates, target, 0, path, res);
    return res;
  }

 private:
  void backtrack(vector<int>& candidates, int target, int start,
                 vector<int>& path, vector<vector<int>>& res) {
    if (target < 0) return;
    if (target == 0) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      backtrack(candidates, target - candidates[i], i, path, res);
      path.pop_back();
    }
  }
};