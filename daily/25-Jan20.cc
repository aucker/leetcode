#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2239: find closest num to zero [E]
   * Time: O(N), Space: O(1)
   *
   * @param nums
   * @return int
   */
  int findClosestNumber(vector<int>& nums) {
    int ans = INT_MAX;
    for (int num : nums) {
      if (abs(num) < abs(ans)) {
        ans = num;
      }
      if (abs(num) == abs(ans)) {
        ans = max(ans, num);
      }
    }
    return ans;
  }
};
