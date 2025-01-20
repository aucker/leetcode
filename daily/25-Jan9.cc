#include <string>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3297: count substrings that can be rearranged to contain a string
   * Time: O(N + |\Sigma|)
   *
   * @param word1
   * @param word2
   * @return long long
   */
  long long validSubstringCount(string word1, string word2) {
    if (word1.length() < word2.length()) return 0;

    int diff[26]{};  // word1 and word2 char diffs
    for (char c : word2) {
      diff[c - 'a']++;
    }

    // count how many alphabet chars that less than word2 in window
    int less = 0;
    for (int d : diff) {
      if (d > 0) {
        less++;
      }
    }

    long long ans = 0;
    int left = 0;
    for (char c : word1) {
      diff[c - 'a']--;
      if (diff[c - 'a'] == 0) {
        // move c to window, occur of c same as word2
        less--;
      }
      while (less == 0) {                     // window is right
        char out_char = word1[left++] - 'a';  // to move out of window
        if (diff[out_char] == 0) {
          // before out_char move out of window, check occur
          // if out_char in window is same as word2 occur
          // when out_char move out of window, out_char in window lt word2
          less++;
        }
        diff[out_char]++;
      }
      ans += left;
    }
    return ans;
  }
};
