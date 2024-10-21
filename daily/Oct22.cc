#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3184: Count pairs that form a complete day I
   * Time: O(N) cause we use sliding window, Space: O(1)
   *
   * @param hours
   * @return int
   */
  int countCompleteDayPairs(vector<int>& hours) {
    int len = hours.size();
    int le = 0, ri = le + 1;
    if (len == 1) return 0;
    int ans = 0;

    while (le < len - 1) {
      if ((hours[le] + hours[ri]) % 24 == 0) {
        ans++;
      }

      if (ri < len - 1) {
        ri++;
      } else {
        le++;
        ri = le + 1;
      }
    }

    return ans;
  }
};
