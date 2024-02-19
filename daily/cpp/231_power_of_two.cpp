#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n == 1) return true;
    if (n < 1) return false;

    while (n % 2 == 0 && n > 1) {
      n /= 2;
    }
    if (n == 1) return true;
    return false;
  }
};
