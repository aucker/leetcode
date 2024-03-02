#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    /// Two pointer approach O(N)
    int n = nums.size();
    int idx = n - 1;
    int le = 0, ri = n - 1;
    vector<int> res(n);
    while (le <= ri) {
      if (abs(nums[le]) > abs(nums[ri])) {
        res[idx] = nums[le] * nums[le];
        ++le;
      } else if (abs(nums[le]) <= abs(nums[ri])) {
        res[idx] = nums[ri] * nums[ri];
        --ri;
      }
      --idx;
    }
    return res;

    /// Using sort O(NlogN)
  }
};