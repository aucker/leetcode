#include <iostream>
using namespace std;

class Solution {
 public:
  bool canAlignWin(vector<int>& nums) {
    int oneSum = 0, twoSum = 0;
    for (int num : nums) {
      if (num > 0 && num < 10) {
        oneSum += num;
      } else {
        twoSum += num;
      }
    }
    return (oneSum == twoSum) ? false : true;
  }
};
