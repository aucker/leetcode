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
  /// @brief trimBST: Given the root of a binary search tree and two integers
  /// low
  /// @param root
  /// @param low
  /// @param high
  /// @return TreeNode*
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return root;
    if (root->val >= low && root->val <= high) {
      root->left = trimBST(root->left, low, high);
      root->right = trimBST(root->right, low, high);
      return root;
    }
    if (root->val < low) {
      return trimBST(root->right, low, high);
    }
    return trimBST(root->left, low, high);
  }

  /**
   * @brief Trapping Rain Water
   * 42. We use double pointer to solve, use the maxle and maxri to store the
   * shorter size of the left and right side. Only if the shorter side can trap
   * the water, so when left is less than the right we loop the left and right
   * side until they meet
   *
   * Time complexity: O(n), we only traverse the height array once
   *
   * @param height
   * @return int
   */
  int trap(vector<int>& height) {
    int n = height.size();
    int le = 0, ri = n - 1;
    int ans = 0;
    int maxle = 0, maxri = 0;
    while (le < ri) {
      if (height[le] < height[ri]) {
        if (maxle < height[le]) {
          maxle = height[le];
        } else {
          ans += (maxle - height[le]);
          ++le;
        }
      } else {
        if (maxri < height[ri]) {
          maxri = height[ri];
        } else {
          ans += (maxri - height[ri]);
          --ri;
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  // write a test case to test trimBST
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(2);
  TreeNode* result = s.trimBST(root, 1, 2);
  cout << result->val << endl;
  cout << result->left->val << endl;
  cout << result->right->val << endl;

  return 0;
}