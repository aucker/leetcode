#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    // int n = points.size();
    // vector<int> x;
    // for(int i=0; i<n; i++) {
    //     x.push_back(points[i][0]);
    // }
    // sort(x.begin(), x.end());
    // int ans = 0;
    // for(int i=1; i<n; i++) {
    //     ans = max(ans, x[i]-x[i-1]);
    // }
    // return ans;
    /// sort is O(NlogN), but we can do it in O(N) using bucket sort

    // int n = points.size();
    // int min_x = INT_MAX, max_x = INT_MIN;
    // for(int i=0; i<n; i++) {
    //     min_x = min(min_x, points[i][0]);
    //     max_x = max(max_x, points[i][0]);
    // }
    // vector<int> bucket(max_x-min_x+1, 0);
    // for(int i=0; i<n; i++) {
    //     bucket[points[i][0]-min_x]++;
    // }
    // int ans = 0;
    // for(int i=1; i<bucket.size(); i++) {
    //     if(bucket[i] > 0 && bucket[i-1] > 0) {
    //         ans = max(ans, i);
    //     }
    // }
    // return ans;

    /// use priority queue w/ O(N)
    int n = points.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
      pq.push(points[i][0]);
    }

    int res = 0;
    int prev = pq.top();
    while (!pq.empty()) {
      int cur = pq.top();
      pq.pop();
      // res = max(res, pq.empty() ? 0 : cur - pq.top());
      res = max(res, cur - prev);
      prev = cur;
    }
    return res;
  }
};