#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Get the Winner object, LC: 1535
   * Time: O(N) traverse once
   * Space: O(1)
   *
   * @param arr, k
   * @return int
   */
  int getWinner(vector<int>& arr, int k) {
    int cur = arr[0], win = 0;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] > cur) {
        cur = arr[i];
        win = 0;
      }

      if (++win == k) {
        break;
      }
    }

    return cur;
  }
};