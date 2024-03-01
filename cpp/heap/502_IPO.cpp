#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    // int n = profits.size();
    // vector<pair<int, int>> projects;
    // for (int i = 0; i < n; ++i) {
    //   projects.push_back({capital[i], profits[i]});
    // }
    // sort(projects.begin(), projects.end());
    // priority_queue<int> pq;
    // int i = 0;
    // while (k--) {
    //   while (i < n && projects[i].first <= w) {
    //     pq.push(projects[i].second);
    //     ++i;
    //   }
    //   if (!pq.empty()) {
    //     w += pq.top();
    //     pq.pop();
    //   }
    // }
    // return w;

    vector<pair<int, int>> cp;
    for (int i = 0; i < capital.size(); ++i) {
      cp.push_back(make_pair(capital[i], profits[i]));
    }

    sort(cp.begin(), cp.end());
    priority_queue<int> pq;
    int cnt = 0, pointer = 0;
    while (k--) {
      // add the profits that capital is enough to invest
      for (; pointer < capital.size() && cp[pointer].first <= w; ++pointer) {
        pq.push(cp[pointer].second);
      }
      // if there is no project that can be invested
      if (pq.empty()) break;
      // heap top is the max profit that can be invested
      w += pq.top();
      pq.pop();
    }
    return w;
  }
};