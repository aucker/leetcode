#include <deque>
#include <iostream>
using namespace std;

class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int ans = 0;
    deque<int> dq;
    for (int ele : tickets) {
      dq.push_back(ele);
    }

    int pivot = tickets[k];

    while (dq.front() > 0) {
      int tmp = dq.front();
      tmp--;
      dq.pop_front();
      dq.push_back(tmp);
    }
  }

};
