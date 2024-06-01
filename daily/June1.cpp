#include <iostream>
using namespace std;

class Solution {
  int c2(int n) { return n > 1 ? n * (n - 1) / 2 : 0; }

 public:
  /**
   * LC: 2928: Distribute Candies among children I
   * MATH
   * Time/Space: O(1)
   */
  int distributeCandies(int n, int limit) {
    return c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) -
           c2(n - 3 * limit - 1);
  }
};
