#include <vector>

using namespace std;
class Solution {
public:
  void traversal(TreeNode* root, int targetSum, int curSum, vector<int>& curPath, vector<vector<int>>& paths) {
    if (!root) return;
    curPath.push_back(root->val);
    if (!root->left && !root->right) {
      if (targetSum == (curSum + root->val)) {
        paths.push_back(curPath);
      }
    }
    traversal(root->left, targetSum, curSum + root->val, curPath, paths);
    traversal(root->right, targetSum, curSum + root->val, curPath, paths);
    curPath.pop_back();
  }
  // DFS helper function here

  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> paths;
    vector<int> curPath;
    int curSum = 0;
    traversal(root, targetSum, curSum, curPath, paths);

    return paths;
  }
}
