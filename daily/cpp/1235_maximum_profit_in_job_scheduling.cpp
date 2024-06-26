#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int numJobs = profit.size();  // length of jobs
    vector<tuple<int, int, int>> jobs(
        numJobs);  // tuple of (start, end, profit)

    for (int i = 0; i < numJobs; ++i) {
      jobs[i] = make_tuple(endTime[i], startTime[i], profit[i]);
    }

    sort(jobs.begin(), jobs.end());
    vector<int> dp(numJobs +
                   1);  // dp[i] = max profit from jobs[0] to jobs[i - 1]

    for (int i = 0; i < numJobs; ++i) {
      auto [endTime, startTime, profit] = jobs[i];

      int latestNonConflictJobIndex =
          upper_bound(jobs.begin(), jobs.begin() + i, startTime,
                      [&](int time, const auto& job) -> bool {
                        return time < get<0>(job);
                      }) -
          jobs.begin();

      dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
    }

    return dp[numJobs];
  }
};