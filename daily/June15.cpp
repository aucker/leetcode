#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2779: max beauty of array [M]
   * Time: O(nlogn), Space: O(1), no other ds introduced
   * Sliding Windows,
   *
   * @param nums
   * @param k
   * @return int
   */
  int maximumBeauty(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 0, le = 0;
    for (int ri = 0; ri < nums.size(); ri++) {
      while (nums[ri] - nums[le] > k * 2) {
        le++;
      }
      ans = max(ans, ri - le + 1);
    }
    return ans;
  }
};