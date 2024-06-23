#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 520: Detect Capital [E]
   * Time: O(N), Space: O(1)
   * use the sugar of isupper(), easy
   *
   * @param word
   * @return true
   * @return false
   */
  bool detectCapitalUse(string word) {
    int cnt = 0;
    for (char c : word) {
      if (isupper(c)) {
        cnt++;
      }
    }

    return cnt == 0 || cnt == word.size() || (cnt == 1 && isupper(word[0]));

    // if (cnt == word.size() || cnt == 0) {
    //   return true;
    // } else if (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z') {
    //   return true;
    // } else {
    //   return false;
    // }
  }
};