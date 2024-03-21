#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Minimum Size Subarray Sum
   * LeetCode 209
   * Given an array of positive integers nums and a positive integer target,
   * return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
   * numsr-1, numsr] of which the sum is greater than or equal to target. If
   * there is no such subarray, return 0 instead.
   *
   * @param target
   * @param nums
   * @return int
   */
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 0;
    int ans = INT_MAX;
    int sum = 0;
    while (end < n) {
      sum += nums[end];
      while (sum >= target) {
        ans = min(ans, end - start + 1);
        sum -= nums[start];
        ++start;
      }
      ++end;
    }
    return ans == INT_MAX ? 0 : ans;
  }

  /**
   * @brief Longest Substring Without Repeating Characters
   * LeetCode 3
   * Given a string s, find the length of the longest substring without
   * repeating
   *
   * @param s
   * @return int
   */
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_set<char> occ;
    int ans = 0, rp = -1;

    for (int i = 0; i < n; ++i) {
      if (i) {
        occ.erase(s[i - 1]);
      }
      while (rp + 1 < n && !occ.count(s[rp + 1])) {
        occ.insert(s[rp + 1]);
        ++rp;
      }
      ans = max(ans, rp - i + 1);
    }

    return ans;
  }
};