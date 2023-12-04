#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
class Solution {
public:
  string largestGoodInteger(string num) {
    int count = 0;
    char prev = 'X', maxd = ' ';
    for (char c : num) {
      if (c == prev) count++;
      else count = 1;
      if (count == 3)
        maxd = max(maxd, c);
      prev = move(c);  // make prev = previous c
    }
    return (maxd == ' ') ? "" : string(3, maxd);  // init a string here
  }
};
