#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3146: Permutaion diffs between two strings
   * TIme: O(N), Space: O(N), use of another ds
   *
   * @param s
   * @param t
   * @return int
   */
  int findPermutationDifference(string s, string t) {
    int ans = 0;
    // unordered_map<char, int> smap;
    // unordered_map<char, int> tmap;
    // for (int i = 0; i < s.length(); i++) {
    //   smap[s[i]] = i;
    //   tmap[t[i]] = i;
    // }
    // for (char c : s) {
    //   ans += abs(smap[c] - tmap[c]);
    // }
    // return ans;

    int len = s.length();
    vector<int> scon(len);
    vector<int> tcon(len);
    for (int i = 0; i < len; i++) {
      scon[i] = s[i];
      tcon[i] = t[i];
    }

    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        if (scon[i] == tcon[j]) {
          ans += abs(i - j);
        }
      }
    }
    return ans;
  }
};
