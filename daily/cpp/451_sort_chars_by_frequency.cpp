#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
      freq[c]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto it : freq) {
      pq.push({it.second, it.first});
    }
    string res = "";
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      res += string(p.first, p.second);
    }
    return res;

    // vector<int> freq(52, 0);
    // for (char c : s) {
    //     if (c >= 'a' && c <= 'z') {
    //         freq[c - 'a']++;
    //     } else {
    //         freq[c - 'A' + 26]++;
    //     }
    // }
    // string res;
    // sort(freq.begin(), freq.end(), greater<int>());
    // for (int i = 0; i < freq.size(); ++i) {
    //     if (freq[i] == 0) {
    //         break;
    //     }
    //     char c = i < 26 ? 'a' + i : 'A' + i - 26;
    //     res += string(freq[i], c);
    // }
    // return res;
  }
};