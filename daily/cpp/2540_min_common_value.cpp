#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCommonValue(vector<int>& nums1, vector<int>& nums2) {
    int sz1 = nums1.size(), sz2 = nums2.size();
    int i = 0, j = 0;
    int res = -1;
    while (i < sz1 and j < sz2) {
      if (nums1[i] == nums2[j]) {
        res = nums1[i];
        break;
      } else if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        ++j;
      }
    }

    return res;
  }
};