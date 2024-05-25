#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * LC:2903: Find indices w/ index and val diffs
   * Time: O(N - indexDifference)
   * Space: O(1)
   */
  vector<int> findIndices(vector<int>& nums, int indexDifference,
                          int valueDifference) {
    int max_idx = 0, min_idx = 0;
    for (int j = indexDifference; j < nums.size(); j++) {
      int i = j - indexDifference;
      if (nums[i] > nums[max_idx]) {
        max_idx = i;
      } else if (nums[i] < nums[min_idx]) {
        min_idx = i;
      }

      if (nums[max_idx] - nums[j] >= valueDifference) {
        return {max_idx, j};
      }
      if (nums[j] - nums[min_idx] >= valueDifference) {
        return {min_idx, j};
      }
    }
    return {-1, -1};
  }

  unordered_map<char, char> rotate = {
      {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

  /**
   * LC: 247: Strobogrammatic number II
   * Time: O(5^(n/2))
   * Space: O(5^(n/2))
   */
  vector<string> findStrobogrammatic(int n) { return helper(n, true); }

  vector<string> helper(int n, bool isHead) {
    if (n == 0) {
      return {""};
    }
    if (n == 1) {
      return {"0", "1", "8"};
    }
    vector<string> res;
    auto mids = helper(n - 2, false);
    for (auto& [k, v] : rotate) {
      if (isHead && k == '0') {
        continue;
      }
      for (auto mid : mids) {
        res.push_back(k + mid + v);
      }
    }
    return res;
  }
};
