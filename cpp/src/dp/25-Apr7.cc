#include <functional>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC416: Partiton Equal Subset Sum
   *
   * @param nums
   * @return true
   * @return false
   */
  bool canPartition(vector<int>& nums) {
    // Early returns for edge cases
    if (nums.empty()) return true;
    if (nums.size() == 1) return false;

    int total = reduce(nums.begin(), nums.end());
    if (total % 2) return false;  // odd sum can't be partitioned

    int target = total / 2;
    int n = nums.size();
    // memo[i][j] = can we make sum j using first i elements
    vector memo(n, vector<int>(target + 1, -1));

    function<bool(int, int)> dfs = [&](int i, int j) {
      if (j == 0) return true;  // base case: sum 0 can always be achieved
      if (i < 0) return false;  // base case: no elements left

      int& res = memo[i][j];
      if (res != -1) return (bool)res;

      // Try including or excluding nums[i]
      bool include = (j >= nums[i]) ? dfs(i - 1, j - nums[i]) : false;
      bool exclude = dfs(i - 1, j);

      return (bool)(res = include || exclude);
    };

    return dfs(n - 1, target);
  }
};
