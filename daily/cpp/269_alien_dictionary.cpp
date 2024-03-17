#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  const int visiting = 1, visited = 2;
  unordered_map<char, vector<char>> edges;
  unordered_map<char, int> states;
  bool valid = true;
  string order;
  int index;

  void addEdge(string before, string after) {
    int len1 = before.size(), len2 = after.size();
    int len = min(len1, len2);
    int index = 0;
    while (index < len) {
      char c1 = before[index], c2 = after[index];
      if (c1 != c2) {
        edges[c1].emplace_back(c2);
        break;
      }
      ++index;
    }
    if (index == len && len1 > len2) {
      valid = false;
    }
  }

  void dfs(char u) {
    states[u] = visiting;
    for (char v : edges[u]) {
      if (!states.count(v)) {
        dfs(v);
        if (!valid) {
          return;
        }
      } else if (states[v] == visiting) {
        valid = false;
        return;
      }
    }
    states[u] = visited;
    order[index] = u;
    --index;
  }

 public:
  string alienOrder(vector<string>& words) {
    int len = words.size();
    for (string& word : words) {
      int wordLen = word.size();
      for (int j = 0; j < wordLen; ++j) {
        char c = word[j];
        if (!edges.count(c)) {
          edges[c] = vector<char>();
        }
      }
    }
    for (int i = 1; i < len && valid; ++i) {
      addEdge(words[i - 1], words[i]);
    }
    order = string(edges.size(), ' ');
    index = edges.size() - 1;
    for (auto [u, _] : edges) {
      if (!states.count(u)) {
        dfs(u);
      }
    }
    if (!valid) {
      return "";
    }
    return order;
  }
};