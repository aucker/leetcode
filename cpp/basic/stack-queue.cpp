#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // use stack to implement queue
  void stack_queue(vector<int> &nums) {
    stack<int> sin, sout;
    for (int &num : nums) {
      sin.push(num);
    }
    while (!sin.empty()) {
      sout.push(sin.top());
      sin.pop();
    }
    // now sout is the reversed version of sin
    while (!sout.empty()) {
      cout << sout.top() << " ";
      sout.pop();
    }
  }
};