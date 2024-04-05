#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSteps(string s, string t) {
    vector<int> cnt_s(26, 0), cnt_t(26, 0);

    for (char c : s) {
      cnt_s[c - 'a']++;
    }
    for (char c : t) {
      cnt_t[c - 'a']++;
    }
    int steps = 0;
    for (int i = 0; i < 26; ++i) {
      steps += abs(cnt_s[i] - cnt_t[i]);
    }
    return steps / 2;
  }
};