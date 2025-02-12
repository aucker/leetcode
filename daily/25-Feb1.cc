#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC81: Search in Rotated Sorted Array II
   * Time: O(N), Space: O(1)
   *
   * @param nums
   * @param target
   * @return BOOL
   */
  bool search(vector<int>& nums, int target) {
    int left = -1, right = nums.size() - 1;  // open (-1, n - 1)
    auto check = [&](int i) -> bool {
      int x = nums[i];
      if (x > nums[right]) {
        return target > nums[right] && x >= target;
      }
      return target > nums[right] || x >= target;
    };

    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == nums[right]) {
        right--;
      } else if (check(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }

    return nums[right] == target;
  }
};
