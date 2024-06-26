#include <bits/stdc++.h>

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size(), l, r, sum;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) continue;

      l = i + 1;
      r = n - 1;

      while (l < r) {
        sum = nums[i] + nums[l] + nums[r];
        if (sum < 0) {
          l++;
        } else if (sum > 0) {
          r--;
        } else {
          res.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) l++;
          while (r > l && nums[r] == nums[r - 1]) r--;
          l++;
          r--;
        }
      }
    }
    return res;
  }
};