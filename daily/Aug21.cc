#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3007: max number that sum of the prices is less or equal than k
   * DP
   *
   * @param k
   * @param x
   * @return long long
   */
  long long findMaximumNumber(long long k, int x) {
    auto check = [&](long long num) {
      int m = __lg(num) + 1;
      vector<vector<long long>> memo(m, vector<long long>(m + 1, -1));
      auto dfs = [&](auto&& dfs, int i, int cnt1, bool is_limit) -> long long {
        if (i < 0) {
          return cnt1;
        }
        if (!is_limit && memo[i][cnt1] >= 0) {
          return memo[i][cnt1];
        }
        int up = is_limit ? num >> i & 1 : 1;
        long long res = 0;
        for (int d = 0; d <= up; d++) {
          // iterate d
          res += dfs(dfs, i - 1, cnt1 + (d == 1 && (i + 1) % x == 0),
                     is_limit && d == up);
        }
        if (!is_limit) {
          memo[i][cnt1] = res;
        }
        return res;
      };
      return dfs(dfs, m - 1, 0, true) <= k;
    };
    long long left = 0, right = (k + 1) << x;
    while (left + 1 < right) {
      long long mid = left + (right - left) / 2;
      (check(mid) ? left : right) = mid;
    }
    return left;
  }
};