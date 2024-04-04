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
  /**
   * @brief Get the Target Copy object
   * DFS solution
   * Time and Space O(N)
   *
   * @param original
   * @param cloned
   * @param target
   * @return TreeNode*
   */
  TreeNode* getTargetCopyDFS(TreeNode* original, TreeNode* cloned,
                             TreeNode* target) {
    if (original == nullptr) return nullptr;

    if (original == target) return cloned;

    TreeNode* left = getTargetCopyDFS(original->left, cloned->left, target);
    if (left != nullptr) {
      return left;
    }

    return getTargetCopyDFS(original->right, cloned->right, target);
  }
  /**
   * @brief Get the Target Copy object BFS
   * Time and Space: O(N)
   *
   * @param original
   * @param cloned
   * @param target
   * @return TreeNode*
   */
  TreeNode* getTargetCopyBFS(TreeNode* original, TreeNode* cloned,
                             TreeNode* target) {
    queue<TreeNode*> q1, q2;
    q1.push(original);
    q2.push(cloned);
    while (!q1.empty()) {
      TreeNode *node1 = q1.front(), *node2 = q2.front();
      q1.pop();
      q2.pop();
      if (node1 == target) {
        return node2;
      }
      if (node1->left != nullptr) {
        q1.push(node1->left);
        q2.push(node2->left);
      }
      if (node1->right != nullptr) {
        q1.push(node1->right);
        q2.push(node2->right);
      }
    }

    return nullptr;  // impossible case
  }

  /**
   * @brief check if two strings are Isomorphic strings
   *
   * @param s
   * @param t
   * @return true
   * @return false
   */
  bool isIsomophic(string s, string t) {
    vector<int> indexS(200, 0);
    vector<int> indexT(200, 0);

    int len = s.length();
    if (len != t.length()) {
      return false;
    }

    for (int i = 0; i < len; i++) {
      if (indexS[s[i]] != indexT[t[i]]) {
        return false;
      }

      indexS[s[i]] = i + 1;
      indexT[t[i]] = i + 1;
    }

    return true;
  }
};

int dr[]{1, -1, 0, 0};
int dc[]{0, 0, 1, -1};

class WordSearch {
 public:
  int n, m;
  vector<vector<char>> board_;
  string word_;

  bool isValid(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) {
      return false;
    }
    return true;
  }

  bool DFS(int r, int c, int ptr) {
    if (ptr == word_.size()) {
      return true;
    }

    if (!isValid(r, c) || board_[r][c] == '0' || word_[ptr] != board_[r][c]) {
      return false;
    }

    char tmp = board_[r][c];
    board_[r][c] = '0';

    for (int i = 0; i < 4; i++) {
      if (DFS(r + dr[i], c + dc[i], ptr + 1)) {
        return true;
      }
    }

    board_[r][c] = tmp;
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    n = board.size(), m = board[0].size();
    board_ = board;
    word_ = word;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (DFS(i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }
};

// Solution() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);
// };