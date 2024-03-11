#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  int maxDepth(Node *root) {
    // bfs
    if (!root) return 0;
    int depth = 0;
    for (Node *cur : root->children) {
      depth = max(depth, maxDepth(cur));
    }
    return depth + 1;
  }
};