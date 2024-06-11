#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 881: Boats to save people
   * GREEDY: Time: O(nlogn), Space: O(logn)
   *
   * @param people
   * @param limit
   * @return int
   */
  int numRescueBoats(vector<int>& people, int limit) {
    int len = people.size();
    int le = 0, ri = len - 1;
    int ans = 0;
    while (le <= ri) {
      if (people[le] + people[ri] <= limit) {
        le++;
      }
      ri--;
      ans++;
    }
    return ans;
  }
};