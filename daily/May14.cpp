#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2244: min rounds to finish the task
   * Time: O(n)
   * Space: O(n)
   * 
   * @param tasks 
   * @return int 
   */
  int minumumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (int t : tasks) {
      cnt[t]++;
    }
    int ans = 0;

    for (auto& [_, c] : cnt) {
      if (c == 1) {
        return -1;
      }
      ans += (c + 2) / 3;
    }
    return ans;
  }
};