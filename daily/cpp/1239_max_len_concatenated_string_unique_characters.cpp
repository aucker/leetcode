#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /** Solution 1: DFS*/
    // int maxLength(vector<string>& arr) {
    //     int n = arr.size();
    //     vector<int> masks;
    //     for (string s : arr) {
    //         int mask = 0;
    //         for (char c : s) {
    //             int ch = c - 'a';
    //             if ((mask & (1 << ch)) != 0) {
    //                 mask = 0;
    //                 break;
    //             }
    //             mask |= (1 << ch);
    //         }
    //         if (mask > 0) {
    //             masks.push_back(mask);
    //         }
    //     }
    //     int ans = 0;
    //     function<void(int, int)> dfs = [&](int pos, int mask) {
    //         if (pos == masks.size()) {
    //             ans = max(ans, __builtin_popcount(mask));
    //             return;
    //         }
    //         if ((mask & masks[pos]) == 0) {
    //             dfs(pos + 1, mask | masks[pos]);
    //         }
    //         dfs(pos + 1, mask);
    //     };
    //     dfs(0, 0);
    //     return ans;
    // }

    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int res = 0;

        for (const string& s : arr) {
            int a = 0, dup = 0;
            for (char c : s) {
                dup |= a & (1 << (c - 'a'));
                a |= 1 << (c - 'a');
            }

            if (dup) continue;  // dup is not 0, means there are duplicate characters in s
            for (int i = dp.size() - 1; i >= 0; --i) {
                if (dp[i] & a) continue;  // dp[i] & a is not 0, means there are duplicate characters between dp[i] and s
                dp.push_back(dp[i] | a);
                res = max(res, __builtin_popcount(dp.back()));
            }
        }
        return res;
    }
};