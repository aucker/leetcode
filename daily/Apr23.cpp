#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int s[2]{}, max_s1 = 0;
    for (int i = 0; i < customers.size(); i++) {
      s[grumpy[i]] += customers[i];
      if (i < minutes - 1) {  // windows size less than minutes
        continue;
      }
      max_s1 = max(max_s1, s[1]);
      // leftmost goes out of window
      s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
    }
    return s[0] + max_s1;
  }

  int maxSatisfied1(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int total = 0;
    int n = customers.size();
    for (int i = 0; i < n; i++) {
      if (grumpy[i] == 0) {
        total += customers[i];
      }
    }
    int increase = 0;
    for (int i = 0; i < minutes; i++) {
      increase += customers[i] * grumpy[i];
    }
    int maxIncrease = increase;
    for (int i = minutes; i < n; i++) {
      increase = increase - customers[i - minutes] * grumpy[i - minutes] +
                 customers[i] * grumpy[i];
      maxIncrease = max(maxIncrease, increase);
    }
    return total + maxIncrease;
  }
};