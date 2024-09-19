#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2414: length of longest alphabetical continuous substring
   * Time: O(N), Space: O(1)
   *
   * @param s
   * @return int
   */
  int longestContinuousSubstring(string s) {
    int ans = 1, cnt = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i - 1] + 1 == s[i]) {
        ans = max(ans, ++cnt);
      } else {
        cnt = 1;
      }
    }
    return ans;
  }
};
