#include <deque>
#include <iostream>
using namespace std;

class Solution {
 public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                    long long budget) {
    int ans = 0, le = 0;
    long long sum = 0;
    deque<int> dq;
    for (int ri = 0; ri < chargeTimes.size(); ri++) {
      // enque
      while (!dq.empty() && chargeTimes[ri] >= chargeTimes[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(ri);
      sum += runningCosts[ri];

      // deque
      while (!dq.empty() &&
             chargeTimes[dq.front()] + (ri - le + 1) * sum > budget) {
        if (dq.front() == le) {
          dq.pop_front();
        }
        sum -= runningCosts[le++];
      }

      ans = max(ans, ri - le + 1);
    }
    return ans;
  }
};
