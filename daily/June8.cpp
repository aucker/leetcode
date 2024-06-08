#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief return the max operations needed to get same score II
   * This time we have options, first two, last two or first and last
   * So this is a DFS problem, use cache or dp
   *
   * @param nums
   * @return int
   */
  int maxOperations(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> memo(len, vector<int>(len));
    auto helper = [&](int i, int j, int target) -> int {
      for (auto& row : memo) {
        std::fill(row.begin(), row.end(), -1);
      }
      function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (i >= j) return 0;
        int& res = memo[i][j];      // reference
        if (res != -1) return res;  // get this before
        res = 0;
        if (nums[i] + nums[i + 1] == target) res = max(res, dfs(i + 2, j) + 1);
        if (nums[j] + nums[j - 1] == target) res = max(res, dfs(i, j - 2) + 1);
        if (nums[i] + nums[j] == target) res = max(res, dfs(i + 1, j - 1) + 1);
        return res;
      };
      return dfs(i, j);
    };
    int res1 = helper(2, len - 1, nums[0] + nums[1]);              // first two nums
    int res2 = helper(0, len - 3, nums[len - 1] + nums[len - 2]);  // last two nums
    int res3 = helper(1, len - 2, nums[0] + nums[len - 1]);        // first and last
    return max({res1, res2, res3}) + 1;                            // add first op
  }

  int maxOperationsOp(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> memo(len, vector<int>(len));
    bool done = false;  // marker
    auto helper = [&](int i, int j, int target) -> int {
      if (done) return 0;
      for (auto& row : memo) {
        std::fill(row.begin(), row.end(), -1);  // no get before
      }
      function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (done) return 0;
        if (i >= j) {
          done = true;
          return 0;
        }
        int& res = memo[i][j];
        if (res != -1) return res;  // got before
        res = 0;
        if (nums[i] + nums[i + 1] == target) res = max(res, dfs(i + 2, j) + 1);
        if (nums[j] + nums[j - 1] == target) res = max(res, dfs(i, j - 2) + 1);
        if (nums[i] + nums[j] == target) res = max(res, dfs(i + 1, j - 1) + 1);
        return res;
      };
      return dfs(i, j);
    };
    int res1 = helper(2, len - 1, nums[0] + nums[1]);              // first two
    int res2 = helper(1, len - 2, nums[0] + nums[len - 1]);        // first and last
    int res3 = helper(0, len - 3, nums[len - 1] + nums[len - 2]);  // last two
    return max({res1, res2, res3}) + 1;                            // all max + 1 op
  }
};