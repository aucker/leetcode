#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LCP: 61: trend of temperature change [E]
   * Time: O(N), Space: O(1)
   *
   * @param temperatureA
   * @param temperatureB
   * @return int */
  int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
    auto cmp = [](int x, int y) { return (x > y) - (x < y); };

    int ans = 0, same = 0;
    for (int i = 1; i < temperatureA.size(); i++) {
      if (cmp(temperatureA[i - 1], temperatureA[i]) ==
          cmp(temperatureB[i - 1], temperatureB[i])) {
        ans = max(ans, ++same);
      } else {
        same = 0;
      }
    }
    return ans;
  }
};