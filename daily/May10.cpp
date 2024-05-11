#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Use the 2-loop
   * Time: O(N^2)
   *
   * @param batteryPercentages
   * @return int
   */
  int countTestedDevices(vector<int>& batteryPercentages) {
    int res = 0;
    int i = 0;
    int len = batteryPercentages.size();
    while (i < len) {
      if (batteryPercentages[i] > 0) {
        res++;
        for (int j = i; j < len; j++) {
          batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
        }
      }

      i++;
    }

    return res;
  }

  /**
   * @brief This is optimized version
   * Time: O(N)
   *
   * @param batteryPercentages
   * @return int
   */
  int countTestedDevicesOP(vector<int>& batteryPercentages) {
    int res = 0;
    for (int x : batteryPercentages) {
      res += res < x;
    }

    return res;
  }
};