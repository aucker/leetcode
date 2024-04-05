#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int size = nums.size();
    int i = 0;
    while (i < size) {
      if (nums[i] == val) {
        nums[i] = nums[size - 1];
        size--;
      } else {
        i++;
      }
    }
    return size;
  }
  /** A typical double pointer */
};