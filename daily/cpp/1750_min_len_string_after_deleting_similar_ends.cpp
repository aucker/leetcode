#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /* Two pointer w/ one traversal */
  int minimumLength(string s) {
    int le = 0, ri = s.size() - 1;
    while (le < ri && s[le] == s[ri]) {
      char c = s[le];
      while (le <= ri && s[le] == c) ++le;
      while (le <= ri && s[ri] == c) --ri;
    }
    return ri - le + 1;
  }
};