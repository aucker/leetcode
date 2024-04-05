
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int minDepth(TreeNode *root) {
    int res = recur(root);
    return res == INT_MAX ? 0 : res;
  }

  int recur(TreeNode *curr) {
    if (!curr) return INT_MAX;
    if (!curr->left && !curr->right) return 1;
    return 1 + min(recur(curr->left), recur(curr->right));
  }
}
