#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2275: Largest Combinations w/ Bitwise AND GT 0
   * Time: O(n logU), n: len(candidate), U = max(candidate)
   * Space: O(1)
   *
   * @param candidates
   * @return int
   */
  int largestCombination(vector<int>& candidates) {
    int m = 0;
    int max_val = *max_element(candidates.begin(), candidates.end());
    while (max_val > 0) {
      max_val >>= 1;
      m++;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int x : candidates) {
        cnt += x >> i & 1;
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};
