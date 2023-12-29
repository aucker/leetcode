#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        num = jd.size();
        if (num < d) return -1;  // cannot divide

        for (int i = 0; i <= num; ++i) {
            for (int j = 0; j <= d; ++j) {
                dp[i][j] = -1;
            }
        }
        int res = solve(0, 0, jd, d);
        return res;
    }

private:
    int num;
    int dp[301][11];
    // num: 1~300
    // d: 1~10
    int solve(int i, int j, vector<int>& jd, int d) {
        if (j > d) return 1e9;
        if (i == num) {
            if (j == d) return 0;
            else return 1e9;
        }

        if (dp[i][j] != -1) return dp[i][j];
        int res = 1e9;
        int mx = jd[i];
        for (int k = i; k < num; ++k) {
            mx = max(mx, jd[k]);  // simultaneously determing max of subarray
            res = min(res, mx + solve(k+1, j+1, jd, d)); // decide where to start new partition from
            // new partition starts from k+1. subarray jd[i, k] is one partition
        }
    }
};