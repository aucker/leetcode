#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dfs(int i, vector<int>& nums, vector<int>& memo) {
    if (i == 0) {  // finish
      return 1;
    }
    int& res = memo[i];  // reference
    if (res != -1) {
      return res;
    }
    res = 0;

    for (int x : nums) {
      if (x <= i) {
        res += dfs(i - x, nums, memo);
      }
    }
    return res;
  }

 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> memo(target + 1, -1);  // -1 not computed before

    return dfs(target, nums, memo);
  }

  int combinationSum4Op(vector<int>& nums, int target) {
    // use unsigned to make overflow still returns normally
    // for the overflow dsata,
    vector<unsigned> f(target + 1);
    f[0] = 1;
    for (int i = 1; i <= target; i++) {
      for (int x : nums) {
        if (x <= i) {
          f[i] += f[i - x];
        }
      }
    }
    return f[target];
  }
};