#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);
    for (int& coin : coins) {
      for (int i = coin; i <= amount; ++i) {
        dp[i] += dp[i - coin];
      }
    }
    return dp[amount];
  }
};