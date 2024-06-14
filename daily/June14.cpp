#include <bits/stdc++.h>

#include <limits>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2786: Visit Array positions to max score
   * This is a DP problem, with optimized solution
   * Time: O(N), Space: O(1)
   * a vector w/ fixed size like 2 is Space complexity of O(1)
   * But a vector space complexity is usually O(N)
   *
   * @param nums
   * @param x
   * @return long long
   */
  long long maxScore(vector<int>& nums, int x) {
    // vector<long long> dp = {INT_MIN, INT_MIN};
    vector<long long> dp(2, numeric_limits<int>::min());
    dp[nums[0] % 2] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int state = nums[i] % 2;
      dp[state] = max(dp[state] + nums[i], dp[abs(state - 1)] + nums[i] - x);
    }
    return max(dp[0], dp[1]);
  }

  // long long maxScoreOP(vector<int>& nums, int x) {
  // bool isEven = nums[0] % 2 == 0;
  // long long oddMax = 0, evenMax = 0;
  // if (isEven) evenMax = nums[0];
  // else oddMax = nums[0];

  // for (size_t i = 1; i < nums.size(); i++) {
  //   isEven = nums[i] % 2 == 0;
  //   if (isEven) evenMax = max(evenMax + nums[i], oddMax + nums[i] - x);
  //   else oddMax = max(oddMax + nums[i], evenMax + nums[i] - x);
  // }
  // return max(oddMax, evenMax);
  // }
};