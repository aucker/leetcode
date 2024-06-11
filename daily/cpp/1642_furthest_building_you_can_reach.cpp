#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    // Priority Queue for storing the bricks used in decreasing order
    priority_queue<int> pq;

    int i = 0, diff = 0;
    for (i; i < heights.size() - 1; ++i) {
      diff = heights[i + 1] - heights[i];

      // clang-format off
      if (diff <= 0) continue;

      bricks -= diff;
      pq.push(diff);
      if (bricks < 0) {
        bricks += pq.top();
        pq.pop();
        --ladders;
      }

      if (ladders < 0) break;
    }
    return i;
  }
};
