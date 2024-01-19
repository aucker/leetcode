#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 || n == 1) return matrix[0][0];

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int res = INT_MAX;

        for (int i = 0; i < m; ++i) {
            res = min(res, help(matrix, 0, i, dp));
        }
        return res;
    }

private:
    int help(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (dp[row][col] != INT_MAX) return dp[row][col];

        if (row == m - 1) return dp[row][col] = matrix[row][col];

        int left = INT_MAX, right = INT_MAX;
        if (col > 0) {
            left = help(matrix, row + 1, col - 1, dp);
        }
        int straight = help(matrix, row + 1, col, dp);
        if (col < n - 1) {
            right = help(matrix, row + 1, col + 1, dp);
        }
        dp[row][col] = min(left, min(straight, right)) + matrix[row][col];

        return dp[row][col];
    }
};