#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
 /**
  * @brief consider the corner case
  *
  * @param nums1
  * @param nums2
  * @param k
  * @return long long
  */
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    unordered_map<int, int> cnt;
    for (int x : nums1) {
      if (x % k) {
        continue;
      }
      x /= k;
      for (int d = 1; d * d <= x; d++) {
        if (x % d) {
          continue;
        }

        cnt[d]++;
        if (d * d < x) {
          cnt[x / d]++;
        }
      }
    }

    long long ans = 0;
    for (int x : nums2) {
      // ans += cnt.contains(x) ? cnt[x] : 0;
      if (cnt.count(x)) {
        ans += cnt[x];
      }
    }

    return ans;
  }

};
