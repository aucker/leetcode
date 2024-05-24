#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * LC: 1673: Most competitive subsequences
   * Time: O(N)
   * Space: O(k) / O(1)
   */
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> st;
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      while (!st.empty() && x < st.back() && st.size() + nums.size() - i > k) {
        st.pop_back();
      }
      if (st.size() < k) {
        st.push_back(x);
      }
    }
    return st;
  }
}
