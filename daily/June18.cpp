#include <bits/stdc++.h>

#include <iomanip>
#include <sstream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2288: Apply Discount to Prices
   * Time: O(N), Space: O(N)
   *
   * @param sentence
   * @param discount
   * @return string
   */
  string discountPrices(string sentence, int discount) {
    double d = 1 - discount / 100.0;
    stringstream ss(sentence);
    string ans, w;
    while (ss >> w) {  // split and add to ans
      if (!ans.empty()) {
        ans += ' ';
      }
      if (w.length() > 1 && w[0] == '$' &&
          all_of(w.begin() + 1, w.end(), ::isdigit)) {
        stringstream s;
        s << fixed << setprecision(2) << '$' << stoll(w.substr(1)) * d;
        ans += s.str();
      } else {
        ans += w;
      }
    }

    return ans;
  }
};