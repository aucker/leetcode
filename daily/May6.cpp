#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MIN));
    f[1][1] = grid[0][0];
    for (int t = 1; t < n * 2 - 1; t++) {
      for (int j = min(t, n - 1); j >= max(t - n + 1, 0); j--) {
        for (int k = min(t, n - 1); k >= j; k--) {
          if (grid[t - j][j] < 0 || grid[t - k][k] < 0) {
            f[j + 1][k + 1] = INT_MIN;
          } else {
            f[j + 1][k + 1] =
                max({f[j + 1][k + 1], f[j + 1][k], f[j][k + 1], f[j][k]}) +
                grid[t - j][j] + (k != j ? grid[t - k][k] : 0);
          }
        }
      }
    }

    return max(f[n][n], 0);
  }
};