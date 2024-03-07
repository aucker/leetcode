#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // use queue to implement stack
  void queue_stack(vector<int> &nums) {
    /// Approach 1: use one queue
    queue<int> q;
    int sz = nums.size();
    for (int &num : nums) {
      q.push(num);
    }
    int cnt = sz;
    while (cnt > 1) {
      for (int i = 0; i < sz - 1; ++i) {
        q.push(q.front());
        q.pop();
      }
      cout << q.front() << " ";  // print the top element
      --cnt;
    }
  }
};