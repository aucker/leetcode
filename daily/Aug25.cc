#include <functional>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC698: partition to K equal sum subsets
   * Time: O(N * 2^N), Space: O(2^N), DP
   *
   * @param nums
   * @param k
   * @return true
   * @return false
   */
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    if (sum % k != 0) {
      return false;
    }
    int per = sum / k;
    sort(nums.begin(), nums.end());
    if (nums.back() > per) {
      return false;
    }
    int len = nums.size();
    vector<bool> dp(1 << len, true);
    // function<bool(int, int)> dfs = [&](int s, int p) -> bool {
    function<bool(int, int)> dfs = [&](int s, int p) -> bool {
      if (s == 0) return true;

      if (!dp[s]) return dp[s];

      dp[s] = false;
      for (int i = 0; i < len; i++) {
        if (nums[i] + p > per) {
          break;
        }
        if ((s >> i) & 1) {
          if (dfs(s ^ (1 << i), (p + nums[i]) % per)) {
            return true;
          }
        }
      }
      return false;
    };

    return dfs((1 << len) - 1, 0);
  }
};
