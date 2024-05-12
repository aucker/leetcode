#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_map<int, int> memo;
  int minDays(int n) {
    if (n <= 1) {
      return n;
    }

    if (memo.count(n)) {
      return memo[n];
    }

    return memo[n] = min(minDays(n / 2) + n % 2, minDays(n / 3) + n % 3) + 1;
  }

  int minDaysDijkstra(int n) {
    unordered_map<int, int> dis;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, n);
    while (true) {
      auto [dx, x] = pq.top();
      pq.pop();
      if (x <= 1) {
        return dx + x;
      }
      if (dx > dis[x]) {
        continue;
      }
      for (int d = 2; d <= 3; d++) {
        int y = x / d;
        int dy = dx + x % d + 1;
        if (!dis.count(y) || dy < dis[y]) {
          dis[y] = dy;
          pq.emplace(dy, y);
        }
      }
    }
  }
};