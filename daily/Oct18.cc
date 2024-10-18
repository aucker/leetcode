#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3191: Min ops to make binary array eles == 1
   * Time: O(N * K), Space: O(1)
   *
   * @param nums
   * @return int
   */
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      if (nums[i] == 0) {
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        ans++;
      }
    }

    return nums[n - 2] && nums[n - 1] ? ans : -1;
  }
};
