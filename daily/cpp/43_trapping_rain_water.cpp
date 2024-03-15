#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int le = 0, ri = n - 1;
    int ans = 0;
    int maxle = 0, maxri = 0;
    while (le < ri) {
      if (height[le] < height[ri]) {
        if (maxle < height[le]) {
          maxle = height[le];
        } else {
          ans += (maxle - height[le]);
          ++le;
        }
      } else {
        if (maxri < height[ri]) {
          maxri = height[ri];
        } else {
          ans += (maxri - height[ri]);
          --ri;
        }
      }
    }
    return ans;
  }
};