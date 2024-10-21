#include <iostream>
using namespace std;

class Solution {
 public:
 /**
  * @brief LCQ1: sequence of strings appeared on screen
  * Time: O(N^2), Space: O(1)
  *
  * @param target
  * @return vector<string>
  */
  vector<string> stringSequence(string target) {
    int len = target.size();
    vector<string> ans;

    for (int i = 0; i < len; i++) {
      char ch = 'a';

      while (target[i] - ch >= 0) {
        string temp = target.substr(0, i);
        temp += ch;
        ans.push_back(temp);

        ch++;
      }
    }

    return ans;
  }

  

};
