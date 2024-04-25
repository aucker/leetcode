#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
};

class SnapshotArray {
 public:
  SnapshotArray(int length) : snap_cnt(0), data(length) {}

  void set(int index, int val) { data[index].emplace_back(snap_cnt, val); }

  int snap() { return snap_cnt++; }

  int get(int index, int snap_id) {
    auto x = upper_bound(data[index].begin(), data[index].end(),
                         pair{snap_id + 1, -1});
    return x == data[index].begin() ? 0 : prev(x)->second;
  }

 private:
  int snap_cnt;
  vector<vector<pair<int, int>>> data;
};