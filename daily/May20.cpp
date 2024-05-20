#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestAwesome(string s) {
    int n = s.size();
    unordered_map<int, int> prefix = {{0, -1}};
    int ans = 0;
    int sequence = 0;
    for (int i = 0; i < n; i++) {
      int digit = s[i] - '0';
      sequence ^= (1 << digit);
      if (prefix.count(sequence)) {
        ans = max(ans, i - prefix[sequence]);
      } else {
        prefix[sequence] = i;
      }
      for (int k = 0; k < 10; k++) {
        if (prefix.count(sequence ^ (1 << k))) {
          ans = max(ans, i - prefix[sequence ^ (1 << k)]);
        }
      }
    }

    return ans;
  }
};