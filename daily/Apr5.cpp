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
  int ans = 0;

  void dfs(TreeNode* node, int mn, int mx) {
    if (!node) return;

    mn = min(mn, node->val);
    mx = max(mx, node->val);
    ans = max(ans, max(node->val - mn, mx - node->val));
    dfs(node->left, mn, mx);
    dfs(node->right, mn, mx);
  }

  void dfsOP(TreeNode* node, int mn, int mx) {
    if (!node) {
      ans = max(ans, mx - mn);
    }

    mn = min(mn, node->val);
    mx = max(mx, node->val);
    dfs(node->left, mn, mx);
    dfs(node->right, mn, mx);
  }

 public:
  int maxAncestorDiff(TreeNode* root) {
    dfs(root, root->val, root->val);
    return ans;
  }
};

class maxDiff {
  int ans = 0;

  pair<int, int> dfs(TreeNode* node) {
    if (!node) {
      return {INT_MAX, INT_MIN};
    }
    auto [l_mn, l_mx] = dfs(node->left);
    auto [r_mn, r_mx] = dfs(node->right);
    int mn = min(node->val, min(l_mn, r_mn));
    int mx = max(node->val, max(l_mx, r_mx));
    ans = max(ans, max(node->val - mn, mx - node->val));
    return {mn, mx};
  }

 public:
  int maxAncestorDiff(TreeNode* root) {
    dfs(root);
    return ans;
  }
};

class FlatBT {
  void preorderRecur(TreeNode* root, vector<TreeNode*>& l) {
    if (root) {
      l.push_back(root);
      preorderRecur(root->left, l);
      preorderRecur(root->right, l);
    }
  }

 public:
  void flatten(TreeNode* root) {
    vector<TreeNode*> l;
    preorderRecur(root, l);
    int n = l.size();
    int i = 0;
    while (i < n) {
      TreeNode *prev = l.at(i - 1), *curr = l.at(i);
      prev->left = nullptr;
      prev->right = curr;
      i++;
    }
  }

  void flattenIter(TreeNode* root) {
    auto v = vector<TreeNode*>();
    auto stk = stack<TreeNode*>();
    TreeNode* node = root;
    while (node || !stk.empty()) {
      while (node) {
        v.push_back(node);
        stk.push(node);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      node = node->right;
    }
    int size = v.size();
    for (int i = 1; i < size; i++) {
      auto prev = v.at(i - 1), curr = v.at(i);
      prev->left = nullptr;
      prev->right = curr;
    }
  }

  void flattenOP(TreeNode* root) {
    if (!root) return;

    auto stk = stack<TreeNode*>();
    stk.push(root);
    TreeNode* prev = nullptr;
    while (!stk.empty()) {
      TreeNode* curr = stk.top();
      stk.pop();
      if (prev) {
        prev->left = nullptr;
        prev->right = curr;
      }

      TreeNode *left = curr->left, *right = curr->right;
      if (right) {
        stk.push(right);
      }
      if (left) {
        stk.push(left);
      }
      prev = curr;
    }
  }

  void flattenPre(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
      if (cur->left) {
        auto next = cur->left;
        auto prede = next;
        while (prede->right) {
          prede = prede->right;
        }

        prede->right = cur->right;
        cur->left = nullptr;
        cur->right = next;
      }
      cur = cur->right;
    }
  }
};