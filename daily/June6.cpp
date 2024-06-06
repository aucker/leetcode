#include <iostream>
using namespace std;

class Solution {
  /**
   * LC: 1938: Separate Black/White Balls
   * Time: O(N), Space: O(1)
   * All the '0's will be left, encounter 0, swap with
   * leftside cnt1, so res += cnt1, until this is no 0 left
   *
   * Note this is also the 'Greedy' solution
   */
  long long minimumSteps(string s) {
    long long ans = 0;
    int cnt1 = 0;
    for (char c : s) {
      if (c == '1') {
        cnt1++;
      } else {
        ans += cnt1;
      }
    }
    return ans;
  }
};
