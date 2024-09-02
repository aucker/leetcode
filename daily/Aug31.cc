#include <iostream>
using namespace std;

class Solution {
 public:
  bool canMakeSquare(vector<vector<char>>& grid) {
    /**
    *  B B B .  B w b
    *  w w w .  w b w
    *  b b b    b w b   b
    */
    int cnt_w = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (grid[i][j] == 'W') {
          cnt_w ++;
        }
      }
    }
    if (cnt_w != 2) return true;
    cnt_w = 0;

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j < 3; j++) {
        if (grid[i][j] == 'W') {
          cnt_w ++;
        }
      }
    }
    if (cnt_w != 2) return true;
    cnt_w = 0;

    for (int i = 1; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        if (grid[i][j] == 'W') {
          cnt_w ++;
        }
      }
    }
    if (cnt_w != 2) return true;
    cnt_w = 0;

    for (int i = 1; i < 3; i++) {
      for (int j = 1; j < 3; j++) {
        if (grid[i][j] == 'W') {
          cnt_w ++;
        }
      }
    }
    if (cnt_w != 2) return true;

    return false;
  }

  /**
   * @brief 138th weekly Q1: key of numbers [E]
   * basic number ops, very easy
   *
   * @param num1 num2 num3
   * @return int
   */
  int generateKey(int num1, int num2, int num3) {
    int ans = 0;
    int flag = 1;
    while (num1 >= 10 || num2 >= 10 || num3 >= 10) {
      int n1 = num1 % 10;
      int n2 = num2 % 10;
      int n3 = num3 % 10;
      num1 /= 10;
      num2 /= 10;
      num3 /= 10;
      ans = ans + flag * min(min(n1, n2), n3);
      flag *= 10;
    }
    ans = ans + flag * min(min(num1, num2), num3);
    return ans;
  }

};
