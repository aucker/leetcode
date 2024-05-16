#include <bits/stdc++.h>

#include <algorithm>
#include <numeric>

using std::accumulate;
using std::max_element;
using std::vector;

class Solution {
 public:
  /**
   * @brief LC1953: max week numbers you can work
   *
   * @param milestones
   * @return int64_t
   */
  auto NumberOfWeeks(vector<int>& milestones) -> int64_t {
    int64_t s = accumulate(milestones.begin(), milestones.end(), 0LL);
    int64_t m = *max_element(milestones.begin(), milestones.end());
    return m > s - m + 1 ? (s - m) * 2 + 1 : s;
  }
};