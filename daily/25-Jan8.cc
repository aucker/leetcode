#include <string>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2264: largest 3-same-digit number in string [E]
   * simple string traversal, build string from char
   * Time: O(N), Space: O(1)
   * @param num
   * @return string
   */
  string largestGoodInteger(string num) {
    char temp = '#';
    for (int i = 1; i < num.length() - 1; i++) {
      if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
        temp = (num[i] > temp) ? num[i] : temp;
      }
    }
    if (temp == '#') return "";
    string ans(3, temp);
    return ans;
  }
};
