#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 521: Longest Uncommon Subsequence
   * Time: O(m+n), Space: O(1)
   *
   * @param a
   * @param b
   * @return int
   */
  int findLUSlength(string a, string b) {
    return a == b ? -1 : max(a.length(), b.length());
  }

  /**
   * @brief LC: 522: Longest Uncommon Subsequences II
   * There are multiple strs, not just one
   * Time: O(n^2* l), l: avg size of strs,  Space: O(1)
   *
   * @param strs
   * @return int
   */
  int findLUSlengthII(vector<string>& strs) {
    auto is_subseq = [](const string& lhs, const string& rhs) -> bool {
      int pt_lhs = 0, pt_rhs = 0;
      while (pt_lhs < lhs.size() && pt_rhs < rhs.size()) {
        if (lhs[pt_lhs] == rhs[pt_rhs]) {
          ++pt_lhs;
        }
        ++pt_rhs;
      }
      return pt_lhs == lhs.size();
    };

    int len = strs.size();
    int ans = -1;
    for (int i = 0; i < len; ++i) {
      bool check = true;
      for (int j = 0; j < len; ++j) {
        if (i != j && is_subseq(strs[i], strs[j])) {
          check = false;
          break;
        }
      }
      if (check) {
        ans = max(ans, static_cast<int>(strs[i].size()));
      }
    }
    return ans;
  }
};