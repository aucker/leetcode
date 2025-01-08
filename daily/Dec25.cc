#include <iostream>
using namespace std;

class Solution {
 public:
  int64_t minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
    ranges::sort(horizontalCut);
    ranges::sort(verticalCut);
    int64_t ans = 0;
    size_t i = 0, j = 0;
    for (size_t k = 0; k < m + n - 2; k++) {
      if (j == verticalCut.size() || (i < horizontalCut.size() && horizontalCut[i] < verticalCut[j])) {
        ans += horizontalCut[i] * (n - j);  // up/down
        ++i;
      } else {
        ans += verticalCut[j] * (m - i);  // left/right
        ++j;
      }
    }
    return ans;
  }

};
