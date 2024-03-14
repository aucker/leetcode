#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
  }

  int numSubarraysWithSum1(vector<int>& nums, int goal) {
    unordered_map<int, int> count;
    count[0] = 1;
    int curr = 0;
    int ans = 0;

    for (int num : nums) {
      curr += num;
      if (count.find(curr - goal) != count.end()) {
        ans += count[curr - goal];
      }
      count[curr]++;
    }

    return ans;
  }

 private:
  int atMost(vector<int>& nums, int goal) {
    int i = 0, j = 0;
    int ans = 0;
    int sum = 0;
    while (j < nums.size()) {
      sum += nums[j];
      while (i < j && sum > goal) {
        sum -= nums[i];
        ++i;
      }
      ans += j - i + 1;
      ++j;
    }
    return ans;
  }
};