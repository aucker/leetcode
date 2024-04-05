#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    /**
     * @brief Use queue to solve
     *
     */
    // if (!root) return nullptr;
    // queue<TreeNode*> q;
    // q.push(root);
    // while (!q.empty()) {
    // 	TreeNode* tmp = q.front();
    // 	q.pop();
    // 	TreeNode* left = tmp->left;
    // 	tmp->left = tmp->right;
    // 	tmp->right = left;

    // 	if (tmp->left != nullptr) q.push(tmp->left);
    // 	if (tmp->right != nullptr) q.push(tmp->right);
    // }
    // return root;

    /**
     * @brief Recursion way to solve
     *
     */
    if (!root) return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};