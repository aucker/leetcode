#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getLengthOfOptimalCompression(string s, int k) {
    /* int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j > 0) dp[i][j] = dp[i - 1][j - 1];
            int cnt = 0, del = 0;
            for (int p = i; p >= 1; --p) {
                if (s[p - 1] == s[i - 1]) ++cnt;
                else ++del;
                if (del > j) break;
                dp[i][j] = min(dp[i][j], dp[p - 1][j - del] + (cnt >= 100 ? 3 :
    cnt >= 10 ? 2 : cnt >= 2 ? 1 : cnt));
            }
        }
    }
    return dp[n][k];
    */

    int n = s.size();
    int m = k;
    int dp[110][110] = {};
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i && j <= m; ++j) {
        int need_remove = 0;
        int group_count = 0;
        dp[i][j] = INT_MAX;
        if (j) {
          dp[i][j] = dp[i - 1][j - 1];
        }
        for (int k = i; k >= 1; --k) {
          if (s[k - 1] != s[i - 1]) {
            need_remove++;
          } else {
            group_count++;
          }

          if (need_remove > j) {
            break;
          }

          if (group_count == 1) {
            dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 1);
          } else if (group_count < 10) {
            dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 2);
          } else if (group_count < 100) {
            dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 3);
          } else {
            dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 4);
          }
        }
      }
    }
    return dp[n][m];
  }
};