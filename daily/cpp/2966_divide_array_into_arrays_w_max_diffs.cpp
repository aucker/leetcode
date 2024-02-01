#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % 3 != 0) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // for (int i = 0; i < n/3; ++i) {
        //     vector<int> tmp;
        //     for (int j = 0; j < 3; ++j) {
        //         if (nums[i*3+j] - nums[i*3] > k) return {};
        //         tmp.push_back(nums[i*3+j]);
        //     }
        //     res.push_back(tmp);
        // }
        for (int i = 0; i <= n - 3; i+=3) {
            if (nums[i+2] - nums[i] > k) return {};
            res.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return res;
    }
};