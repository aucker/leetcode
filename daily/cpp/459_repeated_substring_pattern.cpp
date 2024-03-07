#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    /// Approach 1
    /// Use set to store all the divisors of the length of the string
    /// this is really slow, time complexity is O(n^2)
    // int n = s.size();
    // unordered_set<string> mp;
    // for (int i = 1; i <= n / 2; ++i) {
    //   int len_sub = i + 1;
    //   mp.insert(s.substr(0, len_sub));
    //   for (int j = i + 1; j < n;) {
    //     if (mp.find(s.substr(j, len_sub)) != mp.end() && j + len_sub == n) {
    //       return true;
    //     } else if (mp.find(s.substr(j, len_sub)) == mp.end()) {
    //       mp.clear();
    //       break;
    //     } else {
    //       j += len_sub;
    //     }
    //   }
    // }
    // return false;

    /// Approach 2
    /// Use KMP algorithm
    /// Time Complexity is O(n)
  }

 private:
  bool kmp(const string &query, const string &pattern) {
    int n = query.size();
    int m = pattern.size();
    vector<int> lps(m, -1);
    for (int i = 0; i < m; ++i) {
      int j = lps[i - 1];
      while (j != -1 && pattern[j + 1] != pattern[i]) {
        j = lps[j];
      }
      if (pattern[j + 1] == pattern[i]) {
        lps[i] = j + 1;
      }
    }

    int match = -1;
    for (int i = 1; i <= n; ++i) {
      while (match != -1 && pattern[match + 1] != query[i]) {
        match = lps[match];
      }
      if (pattern[match + 1] == query[i]) {
        ++match;
        if (match == m - 1) {
          return true;
        }
      }
    }
    return false;
  }
};