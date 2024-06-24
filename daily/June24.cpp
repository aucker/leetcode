#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 503: Next Greater Element II
   * Use stack
   * Time: O(N), Space: O(N)
   *
   * @param nums
   * @return vector<int>
   */
  vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(len, -1);

    stack<int> stk;
    for (int i = 2 * len - 1; i >= 0; i--) {
      int x = nums[i % len];
      while (!stk.empty() && x >= stk.top()) {
        stk.pop();
      }
      if (i < len && !stk.empty()) {
        ans[i] = stk.top();
      }
      stk.push(x);
    }
    return ans;
  }

  /**
   * @brief nextGreaterElementsII, but from left to right
   * Still Stack
   * Time: O(N), Space: O(N)
   *
   * @param nums
   * @return vector<int>
   */
  vector<int> nextGreaterElementsII(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(len, -1);
    stack<int> stk;
    for (int i = 0; i < 2 * len; i++) {
      int x = nums[i % len];
      while (!stk.empty() && x > nums[stk.top()]) {
        ans[stk.top()] = x;
        stk.pop();
      }
      if (i < len) {
        stk.push(i);
      }
    }
    return ans;
  }
};