#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief traverse the vector check how many zeros are in the array
   * If more than 1, every res is 0
   * We only need to handle the 1 case
   *
   * @param nums
   * @return vector<int>
   */
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    int num_zeros = 0;
    long long product = 1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        ++num_zeros;
        product *= 1;
      }
      product *= nums[i];
    }

    if (num_zeros > 1) {
      return res;
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        res[i] = product;
      } else if (num_zeros == 1) {
        res[i] = 0;
      } else {
        res[i] = product / nums[i];
      }
    }
    return res;
  }
};