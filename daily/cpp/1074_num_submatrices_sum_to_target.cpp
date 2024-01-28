#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubMatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n, 0);
            for (int j = i; j < m; ++j) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cur = 0;
                for (int k = 0; k < n; ++k) {
                    sum[k] += matrix[j][k];
                    cur += sum[k];
                    if (mp.find(cur - target) != mp.end()) {
                        ans += mp[cur - target];
                    }
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};