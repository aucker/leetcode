#include <iostream>
using namespace std;

class Solution {
 public:
  string removeStars1(string s) {
    string ans;
    stack<char> stk;
    for (char c : s) {
      if (c == '*') {
        stk.pop();
      } else {
        stk.push(c);
      }
    }
    while (!stk.empty()) {
      char c = stk.top();
      ans.push_back(c);
      stk.pop();
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }

  string removeStars2(string s) {
    string ans;
    deque<char> dq;
    for (char c : s) {
      if (c == '*') {
        dq.pop_back();
      } else {
        dq.push_back(c);
      }
    }

    while (!dq.empty()) {
      ans.push_back(dq.front());
      dq.pop_front();
    }
    return ans;
  }

  /**
   * @brief remove stars in a string
   * Use the stack to solve this problem, however, use stack or deque
   * is a little bit complex
   * Remember that `string` also has the `pop_back()` api, just use string.
   *
   * @param s
   * @return string
   */
  string removeStars3(string s) {
    string ans;
    for (char c : s) {
      if (c == '*') {
        ans.pop_back();
      } else {
        ans += c;
      }
    }
    return ans;
  }
};
