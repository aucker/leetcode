#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return -1;

    vector<int> suf(n);  // suffix min
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i > 1; i--) {
      suf[i] = min(suf[i + 1], nums[i]);
    }

    int ans = INT_MAX;
    int pre = nums[0];  // min prefix

    for (int j = 1; j < n - 1; j++) {
      if (pre < nums[j] && nums[j] > suf[j + 1]) {
        ans = min(ans, pre + nums[j] + suf[j + 1]);
      }
      pre = min(pre, nums[j]);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};