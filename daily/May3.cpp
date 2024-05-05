#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double average(vector<int>& salary) {
    sort(salary.begin(), salary.end());
    int len = salary.size();
    double res = 0;
    for (int i = 1; i < len - 1; i++) {
      res += salary[i];
    }
    return res / (len - 2);
  }
};