#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    depth(root, ans);
    return ans;
  }

  int depth(TreeNode* root, int& ans) {
    if (root == nullptr) return 0;
    int l = depth(root->left, ans);
    int r = depth(root->right, ans);
    ans = max(ans, l + r);
    return max(l, r) + 1;
  }
};