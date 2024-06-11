
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
  }

  void dfs(TreeNode* node, vector<int>& res) {
    if (!node) return;

    if (node->left || node->right) {
      dfs(node->left, res);
    }
    res.push_back(node->val);
    if (node->right) {
      dfs(node->right, res);
    }
  }
};
