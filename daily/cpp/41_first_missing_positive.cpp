#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Missing Positive
   * We use a hashtable here, which is extra space of O(N)
   * Which is really slow
   *
   * @param nums
   * @return int
   */
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> seen;
    for (int& num : nums) {
      seen.insert(num);
    }

    for (int i = 1; i < n + 1; ++i) {
      if (seen.find(i) == seen.end()) {
        return i;
      }
    }
    return n + 1;
  }

  int firstMissingPositiveOp(vector<int>& nums) {
    int n = nums.size();
    for (int& num : nums) {
      if (num <= 0) {
        num = n + 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      int num = abs(nums[i]);
      if (num <= n) {
        nums[num - 1] = -abs(nums[num - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    return n + 1;
  }
};