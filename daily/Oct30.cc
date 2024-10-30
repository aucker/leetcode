#include <string>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3216: Get the Smallest String object [E]
   * Basic char/string manipulation, remember substr(i) & concat ops
   * Time: O(N), Space: O(N)
   *
   * @param s
   * @return string
   */
  string getSmallestString(string s) {
    int len = s.length();
    string ans;
    char ch = s[0];
    ans.push_back(ch);

    for (int i = 1; i < len; i++) {
      if (s[i] < s[i - 1] && ((s[i] % 2) == (s[i - 1] % 2))) {
        ans.push_back(s[i - 1]);
        ans[i - 1] = s[i];

        if (i + 1 < len) {
          string slice = s.substr(i + 1);
          ans += slice;
        }
        break;
      } else {
        ans.push_back(s[i]);
      }
    }

    return ans;
  }
};
