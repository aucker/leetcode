#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief we use 2 loops to solve this problem, so the time complexity is O(n^2)
     * 
     * @param nums 
     * @return int 
     */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};