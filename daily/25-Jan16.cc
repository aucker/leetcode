#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC 3095: Shortest subarray w/ OR at least K
   * Time: O(N), Space: O(1)
   *
   * @param nums
   * @param k
   * @return int
   */
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int ans = INT_MAX, left = 0, bottom = 0, right_or = 0;
    for (int right = 0; right < nums.size(); right++) {
      right_or |= nums[right];
      while (left <= right && (nums[left] | right_or) >= k) {
        ans = min(ans, right - left + 1);
        left++;
        if (bottom < left) {
          for (int i = right - 1; i >= left; i--) {
            nums[i] |= nums[i + 1];
          }
          bottom = right;
          right_or = 0;
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }

  /**
   * @brief LogTrick
   * Time: O(n * logU), Space: O(1)
   *
   * @param nums
   * @param k
   * @return int
   */
  int minimumSubarrayLength1(vector<int>& nums, int k) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      if (x >= k) return 1;
      for (int j = i - 1; j >= 0 && (nums[j] | x) != nums[j]; j--) {
        nums[j] |= x;
        if (nums[j] >= k) {
          ans = min(ans, i - j + 1);
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
