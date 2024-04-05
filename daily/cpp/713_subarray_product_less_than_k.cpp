#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC713: Subarray Product Less than K
   * Sliding window
   *
   * @param nums
   * @param k
   * @return int
   */
  int numSubarrayProdctLessThanK(vector<int>& nums, int k) {
    if (k == 0) return 0;
    int cnt = 0, pro = 1;
    for (int i = 0, j = 0; j < nums.size(); ++j) {
      pro *= nums[j];
      while (i <= j && pro >= k) {
        pro /= nums[i++];
      }
      cnt += j - i + 1;
    }
    return cnt;
  }
};