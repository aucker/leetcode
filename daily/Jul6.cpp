#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 3101: Count Alternating Subarries
   * Time: O(N), Space: O(1)
   *
   * @param nums
   * @return long long
   */
  long long countAlternatingSubarrays(vector<int>& nums) {
    long long len = nums.size();
    long long len1 = len;
    long long le = 0, ri = 1;
    long long ans = 0;
    long long tmplen = 1;
    if (len == 1) return 1;
    while (ri < len) {
      while (ri < len && nums[ri] != nums[ri - 1]) {
        tmplen++;
        ri++;
      }
      if (ri < len && nums[ri] == nums[ri - 1]) {
        ri++;
      }
      if (tmplen > 1) {
        len1 -= tmplen;
        ans += ((1 + tmplen) * tmplen / 2);
      }
      tmplen = 1;
    }
    ans += len1;
    return ans;
  }
};