#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief 2798: number of employees who meet the target [E]
   * Time: O(N), just traverse once
   * Space: O(1), no other space used
   *
   * @param hours, target
   * @return int
   */
  int numberOfEmployeesWhoMeetTheTarget(vector<int>& hours, int target) {
    int res = 0;
    for (auto& hour : hours) {
      if (hour >= target) {
        res++;
      }
    }
    return res;
  }
};