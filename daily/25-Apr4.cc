#include <algorithm>
#include <functional>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    TreeNode* ans = nullptr;
    int max_depth = -1;  // max depth

    using DfsFunction = function<int(TreeNode*, int)>;

    function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) {
      if (node == nullptr) {
        max_depth = max(max_depth, depth);
        return depth;
      }

      int left_max_depth = dfs(node->left, depth + 1);
      int right_max_depth = dfs(node->right, depth + 1);
      if (left_max_depth == right_max_depth && left_max_depth == max_depth) {
        ans = node;
      }
      return max(left_max_depth, right_max_depth);
    };

    // auto dfs = [&](auto&& dfs, TreeNode* node, int depth) {
    //   if (node == nullptr) {
    //     max_depth = max(max_depth, depth);
    //     return depth;
    //   }

    //   int left_max_depth = dfs(node->left, depth + 1);
    //   int right_max_depth = dfs(node->right, depth + 1);
    //   if (left_max_depth == right_max_depth && left_max_depth == max_depth) {
    //     ans = node;
    //   }
    //   return max(left_max_depth, right_max_depth);
    // };
    dfs(root, 0);
    return ans;
  }
};
