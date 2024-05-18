#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2644, Too many loops, too slow
   * Time: O(N^2)
   *
   * @param nums
   * @param divisors
   * @return int
   */
  int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    vector<int> tmp(divisors.size(), 0);
    for (int i = 0; i < divisors.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (nums[j] % divisors[i] == 0) {
          tmp[i]++;
        }
      }
    }

    int max_val = *max_element(tmp.begin(), tmp.end());
    vector<int> indices;
    for (int i = 0; i < tmp.size(); i++) {
      if (tmp[i] == max_val) {
        indices.push_back(i);
      }
    }

    int ans = divisors[indices[0]];
    for (int idx : indices) {
      ans = min(ans, divisors[idx]);
    }

    return ans;
  }

  /**
   * @brief Optimize
   * Time: O(nlogn + nm), we use sort here
   *
   * @param nums
   * @param divisors
   * @return int
   */
  int maxDivScoreOP(vector<int>& nums, vector<int>& divisors) {
    sort(nums.rbegin(), nums.rend());
    int max_cnt = -1, ans = 0;
    for (int d : divisors) {
      int cnt = 0;
      for (int x : nums) {
        if (x < d) {
          break;
        }
        if (x % d == 0) {
          cnt++;
        }
      }

      if (cnt > max_cnt || cnt == max_cnt && d < ans) {
        max_cnt = cnt;
        ans = d;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {4, 7, 9, 3, 9};
  vector<int> divisors = {5, 2, 3};
  int res = s.maxDivScore(nums, divisors);
  assert(res == 3);

  return 0;
}
