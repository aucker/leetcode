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

  ll maximumStrength1(vector<int>& nums, int k) {
    dp = vector<vector<vector<ll>>>(
        nums.size(), vector<vector<ll>>(2, vector<ll>(k + 1, -1e16)));
    ll ans = -1e15;
    return solve_optimize(0, (ll)k, false, nums);
  }

  ll maximumStrengthOptimize(vector<int>& nums, int k) {
    ll sum[10005];
    ll cur[10005], last[10005];
    memset(cur, LLONG_MIN, sizeof(cur));
    memset(last, LLONG_MIN, sizeof(last));
    sum[0] = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];

    int flag = 1;
    for (int u = 0; u < k; ++u) {
      int w = (k - u) * flag;
      memcpy(last, cur, sizeof(cur));
      for (int i = u; i <= n; ++i) {
        cur[i] = LLONG_MIN;
      }

      ll tmp = LLONG_MIN;
      for (int i = u; i <= n; ++i) {
        if (i) cur[i] = max(cur[i], cur[i - 1]);
        if (tmp != LLONG_MIN) {
          cur[i] = max(cur[i], tmp + sum[i] * w);
        }
        if (last[i] != LLONG_MIN) {
          tmp = max(tmp, last[i] - sum[i] * w);
        }
      }
      flag = -flag;
    }
    return cur[n];
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

  ll solve_optimize(int i, ll k, bool started, vector<int>& nums) {
    if (k == 0) return 0;
    if (i == nums.size()) {
      if (k == 1 && started) return 0;
      return -1e15;
    }
    if (dp[i][started][k] != -1e16) return dp[i][started][k];

    ll ans = -1e15;

    if (started) {
      ans = solve_optimize(i, k - 1, false, nums);
    }

    ans = max((k % 2 == 0 ? -1 : 1) * k * nums[i] +
                  solve_optimize(i + 1, k, true, nums),
              ans);

    if (!started) {
      ans = max(solve_optimize(i + 1, k, false, nums), ans);
    }
    return dp[i][started][k] = ans;
  }
};