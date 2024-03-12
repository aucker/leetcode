#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  Node* child[26];
  int cnt = 0;
};

class Solution {
 public:
  void add(Node* head, string s, int idx) {
    Node* ptr = head;
    for (int i = idx; i < s.size(); ++i) {
      int c = s[i] - 'a';
      if (!ptr->child[c]) ptr->child[c] = new Node();
      ptr = ptr->child[c];
      ptr->cnt++;
    }
  }

  void remove(Node* head, string s, int idx) {
    Node* ptr = head;
    for (int i = idx; i < s.size(); ++i) {
      ptr = ptr->child[s[i] - 'a'];
      ptr->cnt--;
    }
  }

  string check(Node* head, string s, int idx) {
    Node* ptr = head;
    string ans = "";
    for (int i = idx; i < s.size(); ++i) {
      int c = s[i] - 'a';
      if (!ptr->child[c]) return ans;
      ans += s[i];
      ptr = ptr->child[c];
      if (ptr->cnt < 1) return ans;
    }
    return s + s;
  }

  vector<string> shortestSubstring(vector<string>& arr) {
    vector<string> ans;
    Node* head = new Node();
    for (auto s : arr) {  // add the strings to trie
      for (int i = 0; i < s.size(); ++i) add(head, s, i);
    }

    for (auto s : arr) {
      string res = s + s;
      for (int i = 0; i < s.size(); ++i)
        remove(head, s, i);                 // remove curr string from trie
      for (int i = 0; i < s.size(); ++i) {  // iterate through the substring
        string t = check(head, s, i);
        if (t.size() < res.size() || (t.size() == res.size() && t < res))
          res = t;
      }

      ans.push_back((res.size() <= s.size()) ? res : "");  // add res to ans
      for (int i = 0; i < s.size(); ++i)
        add(head, s, i);  // add curr string back to trie
    }
    return ans;
  }
};