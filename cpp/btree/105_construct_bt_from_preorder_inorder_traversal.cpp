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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    this->preorder = preorder;
    for (int i = 0; i < inorder.size(); ++i) {
      dic[inorder[i]] = i;
    }
    return recur(0, 0, inorder.size() - 1);
  }

 private:
  vector<int> preorder;
  unordered_map<int, int> dic;
  TreeNode* recur(int root, int left, int right) {
    if (left > right) return nullptr;               // end of recursion
    TreeNode* node = new TreeNode(preorder[root]);  // root of the tree
    int i = dic[preorder[root]];                // index of the root in inorder
    node->left = recur(root + 1, left, i - 1);  // left subtree
    node->right = recur(root + i - left + 1, i + 1, right);  // right subtree
    return node;
  }
};