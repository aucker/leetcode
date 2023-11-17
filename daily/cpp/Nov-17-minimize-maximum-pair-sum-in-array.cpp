#include <vector>

using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        int res = 0;
        for (int i = 0; i < l / 2; i++) {
            res = max(res, nums[i] + nums[l - i - 1]);
        }

        return res;
    }
    // ez w/ the sort, but with time complexity of O(nlogn)
}