#include <bits/stdc++.h>
using namespace std;

class NumArray {
 public:
  vector<int> sums;

  NumArray(vector<int>& nums) {
    int len = nums.size();
    sums.resize(len + 1);
    for (int i = 0; i < len; ++i) {
      sums[i + 1] = sums[i] + nums[i];
    }
  }

  int sumRange(int left, int right) { return sums[right + 1] - sums[left]; }
};