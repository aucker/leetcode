#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;

    int curVal = (root->val <= high && root->val >= low) ? root->val : 0;

    int leftSum = rangeSumBST(root->left, low, high);
    int rightSum = rangeSumBST(root->right, low, high);

    return curVal + leftSum + rightSum;
  }
};
