#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
 public:
  int maxmimumLength(string s) {
    // at least 3 times
    vector<int> groups[26];
    int cnt = 0, n = s.length();
    for (int i = 0; i < n; i++) {
      cnt++;
      if (i + 1 == n || s[i] != s[i + 1]) {
        groups[s[i] - 'a'].push_back(cnt);
        cnt = 0;
      }
    }

    // unordered_map<char, int> appear;
    // for (char c : s) {
    //   appear[c]++;
    // }
    // bool check = false;
    // for (auto it = appear.begin(); it != appear.end();) {
    //   if (it->second >= 3) {
    //     check = true;
    //     break;
    //   }
    // }
    int ans = 0;

    for (auto& a : groups) {
      if (a.empty()) continue;
      sort(a.rbegin(), a.rend());
      a.push_back(0);
      a.push_back(0);  // assum two empty string
      ans = max({ans, a[0] - 2, min(a[0] - 1, a[1]), a[2]});
    }

    return ans ? ans : -1;
  }
};