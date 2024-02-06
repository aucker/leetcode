#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> group;

    for (const string& s : strs) {
      group[getSignature(s)].push_back(s);
    }

    for (const auto& entry : group) {
      result.push_back(entry.second);
    }

    return result;
  }

private:
  string getSignature(const string& s) {
    vector<int> count(26, 0);
    for (char c : s) {
      count[c - 'a']++;
    }

    stringstream ss;
    for (int i = 0; i < 26; ++i) {
      ss << (char)('a' + i) << count[i];
    }

    return ss.str();
  }
};
