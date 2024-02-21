#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int rightShift = 0;
    while (left != right) {
      left >>= 1;
      right >>= 1;
      rightShift++;
    }

    return (left << rightShift);
  }
};
