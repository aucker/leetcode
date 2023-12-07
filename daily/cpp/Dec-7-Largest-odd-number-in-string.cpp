#include <string>

using namespace std;
class Solution {
public:
  string largestOddNumber(string num) {
    int pivot = 0;
    for (int i = 0; i < num.size(); ++i) {
      if ((num[i] - '0') % 2 != 0) {
        pivot = i + 1;
      }
    } // at last pivot is the rightmost odd character
    string res = num.substr(0, pivot);

    return res;
  }
};
