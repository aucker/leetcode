#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int ans = 0;
    while (mainTank >= 5) {
      mainTank -= 5;
      ans += 50;
      if (additionalTank) {
        additionalTank--;
        mainTank++;
      }
    }

    return ans + mainTank * 10;
  }
};