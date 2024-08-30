#include <vector>
using namespace std;

class Solution {
 public:
 /**
  * @brief LC3153: Sum of digit diffs of all pairs
  * Time: O(NlogU), Space: O(DlogU), D = 10
  *
  * @param nums
  * @return long long
  */
  long long sumDigitDifferences(vector<int>& nums) {
    long long len = nums.size(), m = to_string(nums[0]).length();
    long long ans = m * len * (len - 1) / 2;
    vector<array<int, 10>> cnt(m);
    for (int x : nums) {
      for (int i = 0; x; x /= 10) {
        ans -= cnt[i++][x %= 10]++;
      }
    }

    return ans;
  }

};
