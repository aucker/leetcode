#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC368: Largest Divisible Subset
   * Time: O(N^2), Space: O(N)
   *
   * @param nums
   * @return vector<int>
   */
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    ranges::sort(nums);
    int n = nums.size();
    vector<int> memo(n), from_(n, -1);

    auto dfs = [&](auto&& dfs, int i) -> int {
      int& res = memo[i];
      if (res) return res;  // memorized
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j]) {
          continue;
        }
        int f = dfs(dfs, j);
        if (f > res) {
          res = f;
          from_[i] = j;
        }
      }
      res++;
      return res;
    };

    int max_f = 0, max_i = 0;
    for (int i = 0; i < n; ++i) {
      int f = dfs(dfs, i);
      if (f > max_f) {
        max_f = f;
        max_i = i;
      }
    }

    vector<int> path;
    for (int i = max_i; i >= 0; i = from_[i]) {
      path.push_back(nums[i]);
    }
    return path;
  }
};
