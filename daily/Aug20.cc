#include <unordered_map>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3154: Find number of ways to Reach k-th stair [H][DP][State][Memo]
   * Time: O()
   *
   * @param k
   * @return int
   */
  int waysToReachStair(int k) {
    unordered_map<long long, int> memo;
    auto dfs = [&](auto&& dfs, int i, int j, bool pre_down) -> int {
      if (i > k + 1) {  // can't to k
        return 0;
      }
      // compress (i, j, pre_down) to long long
      long long mask = (long long)i << 32 | j << 1 | pre_down;
      if (memo.find(mask) != memo.end()) {
        return memo[mask];  // computed before
      }
      int res = i == k;
      res += dfs(dfs, i + (1 << j), j + 1, false);  // op2
      if (i && !pre_down) {
        res += dfs(dfs, i - 1, j, true);  // op1
      }
      return memo[mask] = res;  // memo
    };
    return dfs(dfs, 1, 0, false);
  }
};