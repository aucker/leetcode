#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC1056: confusingNumber
   * Unordered map, time: O(N), Space: O(N)
   *
   * @param n
   * @return true
   * @return false
   */
  bool confusingNumber(int n) {
    unordered_map<char, char> mp = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    auto numstr = to_string(n);
    string newstr = "";
    for (auto& ch : numstr) {
      if (!mp.count(ch)) {
        return false;
      }
      newstr = mp[ch] + newstr;
    }
    return newstr != numstr;
  }
};
