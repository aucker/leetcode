#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC910: Smallest Range II
   * Time: O(NlogN), Sort is O(NlogN), Space: O(1)
   *
   * @param nums
   * @param k
   * @return int
   */
  int smallestRangeII(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = nums.back() - nums[0];

    for (int i = 1; i < nums.size(); i++) {
      int mx = max(nums[i - 1] + k, nums.back() - k);
      int mn = min(nums[0] + k, nums[i] - k);
      ans = min(ans, mx - mn);
    }

    return ans;
  }
};
