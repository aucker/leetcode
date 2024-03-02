#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    /// O(NlogN) solution
    sort(s.rbegin(), s.rend());
    // sort(s.begin(), s.end(), greater<char>());
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '1') {
        // we only need to swap the first 1 we encounter
        swap(s[i], s[s.size() - 1]);
      }
    }
    return s;

    /// O(N) solution
    // int cnt1 = 0, cnt0 = 0;
    // for (char a : s) {
    //   if (a == '1')
    //     cnt1++;
    //   else
    //     cnt0++;
    // }
    // string ans = string(cnt1 - 1, '1') + string(cnt0, '0') + '1';
    // return ans;
  }
};