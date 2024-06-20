#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2748: Number of Beautiful Pairs [M]
   * Time: O(n*(k + logU)), n: len(nums), k = 10, U=max(nums)
   * Time complexity of gcd is O(1)
   * Space: O(k)
   *
   * @param nums
   * @return int
   */
  int countBeautifulPairs(vector<int>& nums) {
    int ans = 0, cnt[10]{};
    for (int x : nums) {
      for (int y = 1; y < 10; y++) {
        if (cnt[y] && gcd(y, x % 10) == 1) {
          ans += cnt[y];
        }
      }
      while (x >= 10) {
        x /= 10;
      }
      cnt[x]++;  // count times of highest
    }
    return ans;
  }
};