#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int ans = 0;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int x : nums) {
      pq.push((ll)x);
    }
    while (pq.top() < k) {
      ll x = pq.top();
      pq.pop();
      ll y = pq.top();
      pq.pop();
      pq.push(x * 2 + y);
      ans++;
    }

    return ans;
  }
};