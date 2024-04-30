#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string baseNeg2(int n) {
    if (n == 0) {
      return "0";
    }

    vector<int> bits(32);
    for (int i = 0; i < 32 && n != 0; i++) {
      if (n & 1) {
        bits[i]++;
        if (i & 1) {
          bits[i + 1]++;
        }
      }
      n >>= 1;
    }
    int carry = 0;
    for (int i = 0; i < 32; i++) {
      int val = carry + bits[i];
      bits[i] = val & 1;
      carry = (val - bits[i]) / (-2);
    }
    int pos = 31;
    string res;
    while (pos >= 0 && bits[pos] == 0) {
      pos--;
    }
    while (pos >= 0) {
      res.push_back(bits[pos] + '0');
      pos--;
    }
    return res;
  }
};

class Weekly395 {
 public:
  int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    return nums2[0] - nums1[0];
  }

  int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int tmp1 = nums2[0] - nums1[0];
    int tmp2 = nums2[0] - nums1[1];
    int tmp3 = nums2[0] - nums1[2];
    int tmp4 = nums2[len2 - 1] - nums1[len1 - 1];
    if (tmp4 == tmp1 || tmp4 == tmp2 || tmp4 == tmp3) return tmp4;
    if (tmp1 == tmp2 || tmp1 == tmp3) return tmp1;
    if (tmp2 == tmp3) return tmp2;
  }
};