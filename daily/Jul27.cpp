#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Get the Smallest String object
   * Greedy: Time: O(n), Space: O(1), in-place
   *
   * @param s
   * @param k
   * @return string
   */
  string getSmallestString(string s, int k) {
    for (char& c : s) {
      int dis = min('z' - c + 1, c - 'a');
      if (dis > k) {
        c -= k;
        break;
      }
      c = 'a';
      k -= dis;
    }
    return s;
  }
};