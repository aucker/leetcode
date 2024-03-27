#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> seen;
    int le = 0, ri = 0;
    int ans = 0;

    while (ri < n) {
      int curr = nums[ri++];
      seen[curr]++;

      while (le < ri && seen[curr] > k) {
        seen[nums[le++]]--;
      }
      ans = max(ans, ri - le);
    }

    return ans;
  }
};