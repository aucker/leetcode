#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    int len = costs.size();
    if (candidates * 2 + k > len) {
      std::ranges::nth_element(costs, costs.begin() + k);
      return accumulate(costs.begin(), costs.begin() + k, 0LL);
    }

    priority_queue<int, vector<int>, greater<>> pre, suf;
    for (int i = 0; i < candidates; i++) {
      pre.push(costs[i]);
      suf.push(costs[len - 1 - i]);
    }

    long long ans = 0;
    int i = candidates, j = len - 1 - candidates;
    while (k--) {
      if (pre.top() <= suf.top()) {
        ans += pre.top();
        pre.pop();
        pre.push(costs[i++]);
      } else {
        ans += suf.top();
        suf.pop();
        suf.push(costs[j--]);
      }
    }
    return ans;
  }
};