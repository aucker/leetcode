#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3134: Median of the uniqueness array [H]
   * Sliding window. Time: O(NlogN), Space: O(N)
   *
   * @param nums
   * @return int
   */
  int medianOfUniquenessArray(vector<int>& nums) {
    int len = nums.size();
    long long k = ((long long)len * (len + 1) / 2 + 1) / 2;

    auto check = [&](int upper) {
      long long cnt = 0;
      int l = 0;
      unordered_map<int, int> freq;
      for (int r = 0; r < len; r++) {
        freq[nums[r]]++;               // expand right
        while (freq.size() > upper) {  // too many elements in window
          int out = nums[l++];
          if (--freq[out] == 0) {  // out left
            freq.erase(out);
          }
        }
        cnt += r - l + 1;  // right is r, r - l + 1
        if (cnt >= k) {
          return true;
        }
      }
      return false;
    };
    int le = 0, ri = len;
    while (le + 1 < ri) {
      int mid = (le + ri) / 2;
      (check(mid) ? ri : le) = mid;
    }
    return ri;
  }
};
