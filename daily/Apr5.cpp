#include <bits/stdc++.h>
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