#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2663: Lexicographically Smallest Beautiful string
   * Greedy algorithm
   * Time: O(N), N: len(s), Space: O(1), inplace update
   *
   * @param s
   * @param k
   * @return string
   */
  string smallestBeautifulString(string s, int k) {
    k += 'a';
    int n = s.length();
    int i = n - 1;  // start from last letter

    s[i]++;
    while (i < n) {
      if (s[i] == k) {  // go upgrade
        if (i == 0) {   // can't go upgrade
          return "";
        }
        // go upgrade
        s[i] = 'a';
        s[--i]++;
      } else if (i && s[i] == s[i - 1] || i > 1 && s[i] == s[i - 2]) {
        s[i]++;  // if s[i] form the
      } else {
        i++;  // check the latter
      }
    }
    return s;
  }
};