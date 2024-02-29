#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    int level = 0;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      int prev = (level % 2 == 0) ? numeric_limits<int>::min()
                                  : numeric_limits<int>::max();

      for (int i = 0; i < size; ++i) {
        TreeNode *node = q.front();
        q.pop();

        if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev)) ||
            (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev))) {
          return false;
        }

        prev = node->val;

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      ++level;
    }

    return true;
  }
};