#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pivotInteger(int n) {
    // 1. use the math directly, sqrt((n * n + n) / 2)
    int ans = sqrt((n * n + n) / 2);
    if (ans * ans == ((n * n + n) / 2)) {
      return ans;
    }
    return -1;

    // 2. traverse from 1 to n, use vector to store
    if (n == 1) return 1;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      nums.push_back(i + 1);
    }
    int sum = 0;
    vector<int> sums;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      sums.push_back(sum);
    }

    int totalSum = 0;
    totalSum = sum;
    sum = 0;
    for (int i = 0; i < n; ++i) {
      if (sum == totalSum - sum - nums[i]) {
        return i + 1;
      }
      sum += nums[i];
    }
    return -1;
  }
};