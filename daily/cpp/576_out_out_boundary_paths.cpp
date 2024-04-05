#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
    const int M = 1e9 + 7;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[startRow][startCol] = 1;
    int count = 0;

    for (int moves = 1; moves <= maxMove; ++moves) {
      vector<vector<int>> tmp(m, vector<int>(n, 0));

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i == m - 1) count = (count + dp[i][j]) % M;
          if (j == n - 1) count = (count + dp[i][j]) % M;
          if (i == 0) count = (count + dp[i][j]) % M;
          if (j == 0) count = (count + dp[i][j]) % M;
          tmp[i][j] =
              (((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) %
                   M +
               ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) %
                   M) %
              M;
        }
      }
      dp = tmp;
    }
    return count;
  }
};