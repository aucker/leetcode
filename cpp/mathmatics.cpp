#include <bits/stdc++.h>
using namespace std;

class Pow {
 public:
  // quick multiply by binary (D&C) (divide & conquer)
  double quickMul(double x, long long N) {
    if (N == 0) {
      return 1.0;
    }
    double y = quickMul(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
  }

  /**
   * @brief Method 1 use recursive way to find
   * Time: O(logN)
   * Space: O(logN) : recursive will call stack space
   *
   * @param x
   * @param n
   * @return double
   */
  double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
  }

  /************************ Use iteration ***********************/
  double quickMulIt(double x, long long N) {
    double ans = 1.0;
    // contribution init is x
    double x_contribute = x;
    // N
    while (N > 0) {
      if (N % 2 == 1) {
        // if N low is 1, contribute
        ans *= x_contribute;
      }
      //
      x_contribute *= x_contribute;
      // drop the low of N binary
      N /= 2;
    }
    return ans;
  }

  double myPowIt(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMulIt(x, N) : 1.0 / quickMulIt(x, -N);
  }
};