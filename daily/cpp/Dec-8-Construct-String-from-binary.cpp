#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  string tree2str(TreeNode* root) {
    string res = "";
    check(root, res);
    return res;
  }

  void check(TreeNode* root, string& str) {
    if (!root) return;

    str += to_string(root->val);
    if (root->left || root->right) {
      str += '(';
      check(root->left, str);
      str += ')';
    }

    if (root->right) {
      str += '(';
      check(root->right, str);
      str += ')';
    }
  }
};
