#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2t, t2s;
    for (int i = 0; i < s.size(); i++) {
      if (s2t.find(s[i]) != s2t.end() && s2t[s[i]] != t[i]) return false;
      if (t2s.find(t[i]) != t2s.end() && t2s[t[i]] != s[i]) return false;
      s2t[s[i]] = t[i];
      t2s[t[i]] = s[i];
    }
    return true;
  }
};