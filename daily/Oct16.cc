#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3194: Min average of smallest and largest elements
   * Easy double pointer solution
   * Time: O(NlogN), Space: O(1)
   *
   * @param nums
   * @return double
   */
  double minimumAverage(vector<int>& nums) {
    double res = INT_MAX;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int le = 0, ri = len - 1;

    while (le < ri) {
      res = min(res, (nums[le] + nums[ri]) / 2.0);
      le++;
      ri--;
    }

    return res;
  }
};
