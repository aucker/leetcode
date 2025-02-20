#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Time: O(NlogU), U = max(nums)
   * Space: O(1)
   *
   * @param nums
   * @param maxOperations
   * @return int
   */
  int minimumSize(vector<int>& nums, int maxOperations) {
    auto check = [&](int m) -> bool {
      long long cnt = 0;
      for (int x : nums) {
        cnt += (x - 1) / m;
      }
      return cnt <= maxOperations;
    };

    int left = 0;
    int right = ranges::max(nums);
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      (check(mid) ? right : left) = mid;
    }
    return right;
  }
};
