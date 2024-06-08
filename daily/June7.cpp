#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 3038: max number of Ops w/ same score I [E]
   * Time: O(n), Space: O(1)
   *
   * @param nums
   * @return int
   */
  int maxOperations(vector<int>& nums) {
    int ans = 1;
    int len = nums.size();
    int pivot = nums[0] + nums[1];
    for (int i = 2; i + 1 < len; i += 2) {
      // if (i + 1 >= len || nums[i] + nums[i + 1] != pivot) {
      // break;
      // }
      if (nums[i] + nums[i + 1] == pivot) {
        ans++;
      } else {
        return ans;
      }
    }
    return ans;
  }
};