#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zeros = 0, ones = count(s.begin(), s.end(), '1');
        int res = 0;

        for (int i = 0; i < n - 1; ++i) {
            zeros += (s[i] == '0');
            ones -= (s[i] == '1');
            res = max(res, zeros + ones);
        }
        return res;
    }
};