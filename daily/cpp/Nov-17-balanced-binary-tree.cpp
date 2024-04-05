class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    if (height(root) == -1) return false;
    return true;
  }

 private:
  int height(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    if (leftH == -1 || rightH == -1 || abs(leftH - rightH) > 1) return -1;
    return max(leftH, rightH) + 1;
  }
  // there is recursive helper function, time complexity is O(n)
}