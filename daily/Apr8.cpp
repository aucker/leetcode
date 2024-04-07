#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2009: min number of ops make array continuous
   * use Sliding Windows
   *
   * @param nums
   * @return int
   */
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    // ranges::sort(nums);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());  // remove dup
    int ans = 0, left = 0;
    for (int i = 0; i < nums.size(); i++) {
      while (nums[left] < nums[i] - n + 1) {
        // nums[left] not in windows
        left++;
      }
      ans = max(ans, i - left + 1);
    }
    return n - ans;
  }

  /**
   * @brief LC678: valid parenthesis string
   * Simple Stack simulation
   *
   * @param s
   * @return true/false bool
   */
  bool checkValidString(string s) {
    int lemin = 0, lemax = 0;

    for (char ch : s) {
      if (ch == '(') {
        lemin++;
        lemax++;
      } else if (ch == ')') {
        lemin--;
        lemax--;
      } else {
        lemin--;
        lemax++;
      }
      if (lemax < 0) return false;
      if (lemin < 0) lemin = 0;
    }

    return lemin == 0;
  }
};