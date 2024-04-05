#include <string>
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
  void path(TreeNode* root, int& sum, int& num) {
    if (!root) return;
    if (!root->left && !root->right) {
      sum += num * 10 + root->val;
      return;
    }
    num = num * 10 + root->val;
    path(root->left, sum, num);
    path(root->right, sum, num);
    num /= 10;
  }

  int sumNumbers(TreeNode* root) {
    int res = 0, num = 0;
    path(root, res, num);
    return res;
  }
}
