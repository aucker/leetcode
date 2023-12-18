#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProductDiffs(vector<int>& nums) {
        /// sort is O(nlogn), which is very slow
        // int len = nums.size();
        // sort(nums.begin(), nums.end());
        // int res = 0;
        // res = nums[len-1] * nums[len-2] - nums[0] * nums[1];
        // return res;

        /// use min and max to find the max and min value
        // int min1 = INT_MAX, min2 = INT_MAX;
        // int max1 = INT_MIN, max2 = INT_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] < min1) {
        //         min2 = min1;
        //         min1 = nums[i];
        //     } else if (nums[i] < min2) {
        //         min2 = nums[i];
        //     }
        //     if (nums[i] > max1) {
        //         max2 = max1;
        //         max1 = nums[i];
        //     } else if (nums[i] > max2) {
        //         max2 = nums[i];
        //     }
        // }
        // int res = 0;
        // res = max1 * max2 - min1 * min2;
        // return res;


        /// more faster way
        int min1{numeric_limits<int>::max()};
        int min2{numeric_limits<int>::max()};
        int max1{numeric_limits<int>::min()};
        int max2{numeric_limits<int>::min()};
        for (const auto num : nums) {
            if (num > max2) {
                max1 = exchange(max2, num);
            } else {
                max1 = max(max1, num);
            }

            if (num < min1) {
                min2 = exchange(min1, num);
            } else {
                min2 = min(min2, num);
            }
        }
        return max1 * max2 - min1 * min2;
    }
};

static const auto _ = []() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return nullptr;
}();