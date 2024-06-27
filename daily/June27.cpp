#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2734: Lexicographically Smallest string after substring ops
   * Time: O(N), Space: O(1), in-place update s of O(1) space
   *
   * @param s
   * @return string
   */
  string smallestString(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] > 'a') {
        // forward
        for (; i < n && s[i] > 'a'; i++) {
          s[i]--;
        }
        return s;
      }
    }
    // all letter is 'a'
    s.back() = 'z';
    return s;
  }
};