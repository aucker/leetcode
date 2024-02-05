#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> vc(26, 0);

    for (char c : s) {
      vc[c - 'a']++;
    }

    for (int i = 0; i < s.size(); ++i) {
      if (vc[s[i] - 'a'] == 1) return i;
    }

    return -1;
  }
};
