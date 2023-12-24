#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        // int n = s.size();
        // int res = 0;
        // for (int i = 0; i < n; ++i) {
        //     if (s[i] - '0' != i % 2) {
        //         res += 1;
        //     }
        // }
        // return min(res, n - res);


        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    cnt1++;
                } else {
                    cnt0++;
                }
            } else {
                if (s[i] == '1') {
                    cnt1++;
                } else {
                    cnt0++;
                }
            }
        }
        return min(cnt0, cnt1);
    }
};