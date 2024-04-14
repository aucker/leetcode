#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Just like map, change the value of edges
   * Time: O(n), only one traverse
   * @param n, edges
   * @return int
   */
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> ans(n);
    for (auto& edge : edges) ans[edge[1]]++;

    int champion = -1;
    for (int i = 0; i < n; i++) {
      if (ans[i] == 0) {
        if (champion != -1) return -1;
        champion = i;
      }
    }
    return champion;
  }

  // Same idea, same way
  int findChampion1(int n, vector<vector<int>>& edges) {
    vector<int> is_weak(n);
    for (auto& e : edges) {
      is_weak[e[1]] = true;  // not chapion, in degree > 0
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (is_weak[i]) {
        continue;
      }
      if (ans != -1) {
        return -1;  // more than one champion
      }
      ans = i;
    }
    return ans;
  }
};

class MovingAverage {
  int size;
  double sum;
  queue<int> q;

 public:
  // MovingAverage(int size) {
  //   this->size = size;
  //   this->sum = 0.0;
  // }

  // this 2 types of construtor works same way
  MovingAverage(int size) : size(size), sum(0.0) {}

  double next(int val) {
    if (size == q.size()) {
      sum -= q.front();
      q.pop();
    }
    q.emplace(val);
    sum += val;
    return sum / q.size();
  }
};

class Contest138 {
 public:
  int scoreOfString(string s) {
    int res = 0;
    for (int i = 1; i < s.size(); i++) {
      res += abs(s[i] - s[i - 1]);
    }
    return res;
  }

  // int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
  //   // no need to care about hhe second value
  //   int xsz = points.size();
  //   unordered_map<int, int> mp;
  //   for (int i = 0; i < xsz; i++) {
  //     // int x = points[i];
  //     mp[points[i]]++;
  //   }
  // }
};