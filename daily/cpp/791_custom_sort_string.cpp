#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string customSortString(string order, string s) {
    unordered_map<char, int> charCnt;
    for (char& c : order) {
      charCnt[c] = 0;
    }
    for (char& c : s) {
      charCnt[c]++;
    }

    string res;
    for (char& c : order) {
      res.append(charCnt[c], c);
    }
    for (char& c : s) {
      if (charCnt.find(c) == charCnt.end()) {
        res.push_back(c);
      }
    }
    return res;
  }
};