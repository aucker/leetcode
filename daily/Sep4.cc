#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2860: happy students [M]
   * Permutation, sort, Time: O(NlogN), Space: O(1)
   *
   * @param nums
   * @return int
   */
  int countWays(vector<int>& nums) {
    int ans = nums[0] > 0;  // non selected
    for (int i = 1; i < nums.size(); i++) {
      ans += nums[i - 1] < i && i < nums[i];
    }
    return ans + 1;  // all selected
  }
};
