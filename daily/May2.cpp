#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size(), sum_q = 0;
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    // ranges::sort(id, [&](int i, int j) {
    //   return wage[i] * quality[j] < wage[j] * quality[i];
    // });  // sort by r value
    sort(id.begin(), id.end(), [&](int i, int j) {
      return wage[i] * quality[j] < wage[j] * quality[i];
    });  // sort by r value
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
      pq.push(quality[id[i]]);
      sum_q += quality[id[i]];
    }
    double ans = sum_q * ((double)wage[id[k - 1]] /
                          quality[id[k - 1]]);  // select r value
    for (int i = k; i < n; i++) {
      int q = quality[id[i]];
      if (q < pq.top()) {
        sum_q -= pq.top() - q;
        pq.pop();
        pq.push(q);
        ans = min(ans, sum_q * ((double)wage[id[i]] / q));
      }
    }

    return ans;
  }
};