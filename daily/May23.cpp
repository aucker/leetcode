#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC 2831: Longest Equal Subarray
   * Time: O(N)
   * Space: O(N)
   *
   * @param nums, k
   * @return int
   */
  int longestEqualSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> pos_lists(n + 1);
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      pos_lists[x].push_back(i - pos_lists[x].size());
    }

    int ans = 0;
    for (auto& pos : pos_lists) {
      int left = 0;
      for (int right = 0; right < pos.size(); right++) {
        while (pos[right] - pos[left] > k) {
          left++;
        }
        ans = max(ans, right - left + 1);
      }
    }
    return ans;
  }
};