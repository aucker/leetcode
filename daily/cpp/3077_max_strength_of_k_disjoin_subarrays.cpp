#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  ll maximumStrength(vector<int>& nums, int k) {
    dp = vector<vector<vector<ll>>>(
        nums.size(), vector<vector<ll>>(k + 1, vector<ll>(2, -1e16)));
    ll ans = -1e15;
    return solve(0, (ll)k, false, nums);
  }

 private:
  vector<vector<vector<ll>>> dp;

  ll solve(int i, ll k, bool started, vector<int>& nums) {
    if (k == 0) return 0;

    if (i == nums.size()) {
      if (k == 1 && started) return 0;
      return -1e15;
    }
    if (dp[i][k][started] != -1e16) return dp[i][k][started];

    ll ans = -1e15;

    if (started) {
      ans = solve(i, k - 1, false, nums);
    }

    ans = max((k % 2 == 0 ? -1 : 1) * k * nums[i] + solve(i + 1, k, true, nums),
              ans);

    if (!started) {
      ans = max(solve(i + 1, k, false, nums), ans);
    }

    return dp[i][k][started] = ans;
  }
};