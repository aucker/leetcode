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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  void path(TreeNode* node, int& sum, int& num) {
    if (!node) return;
    if (!node->left && !node->right) {
      sum = num * 10 + node->val;
    }
    num = num * 10 + node->val;
    path(node->left, sum, num);
    path(node->right, sum, num);
    num /= 10;
  }

 public:
  /**
   * @brief LC.129: Sum Root to Leaf Numbers
   * A recursive problem
   *
   * @param root
   * @return int
   */
  int sumNumbers(TreeNode* root) {
    int ans = 0, num = 0;
    path(root, ans, num);
    return ans;
  }

  /**
   * @brief LC. reverse a LinkedList
   *
   * @param head
   * @return ListNode*
   */
  ListNode* reverseList(ListNode* head) {
    ListNode* ans = nullptr;

    while (head) {
      ListNode* tmp = new ListNode(head->val);
      tmp->next = ans;
      ans = tmp;
      head = head->next;
    }

    return ans;
  }

  ListNode* reverseListIter(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  ListNode* reverseListRecur(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }

  /**
   * @brief 1156: Swap for Longest Repeated Character Substring
   * M
   *
   * @param text
   * @return int
   */
  int maxRepOpt1(string text) {
    unordered_map<char, int> count;
    for (char c : text) {
      count[c]++;
    }

    int ans = 0;
    for (int i = 0; i < text.size();) {
      int j = i;
      while (j < text.size() && text[i] == text[j]) {
        ++j;
      }
      int cur_cnt = j - i;

      // step 2:
      if (cur_cnt < count[text[i]] && (j < text.size() || i > 0)) {
        ans = max(ans, cur_cnt + 1);
      }

      // step 3
      int k = j + 1;
      while (k < text.size() && text[k] == text[i]) {
        ++k;
      }
      ans = max(ans, min(k - i, count[text[i]]));
      i = j;
    }
    return ans;
  }

  /**
   * @brief 200: Number of Islands
   * For DFS, time complexity: O(MN)
   * space complexity: O(MN)
   *
   * For BFS, time complexity: O(MN)
   * space complexity: O(min(M, N))
   *
   * @param grid
   * @return int
   */
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++ans;
          // use DFS for the answer
          dfs(grid, r, c);
        }
      }
    }
    return ans;
  }

  int numIslandsBFS(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int ans = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++ans;
          grid[r][c] = '0';
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row - 1][col] == '1') {
              neighbors.push({row - 1, col});
              grid[row - 1][col] = '0';
            }
            if (row + 1 < nr && grid[row + 1][col] == '1') {
              neighbors.push({row + 1, col});
              grid[row + 1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col - 1] == '1') {
              neighbors.push({row, col - 1});
              grid[row][col - 1] = '0';
            }
            if (col + 1 < nc && grid[row][col + 1] == '1') {
              neighbors.push({row, col + 1});
              grid[row][col + 1] = '0';
            }
          }
        }
      }
    }
    return ans;
  }

  int numIslandsUnionFind(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    UnionFind uf(grid);
    int ans = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          grid[r][c] = '0';
          if (r - 1 >= 0 && grid[r - 1][c] == '1')
            uf.unite(r * nc + c, (r - 1) * nc + c);
          if (r + 1 < nr && grid[r + 1][c] == '1')
            uf.unite(r * nc + c, (r + 1) * nc + c);
          if (c - 1 >= 0 && grid[r][c - 1] == '1')
            uf.unite(r * nc + c, r * nc + c - 1);
          if (c + 1 < nc && grid[r][c + 1] == '1')
            uf.unite(r * nc + c, r * nc + c + 1);
        }
      }
    }

    return uf.getCount();
  }

  /**
   * @brief check if there is a path that adds to targetSum in BT
   *
   * @param root
   * @param targetSum
   * @return true
   * @return false
   */
  bool hasPathSum(TreeNode* root, int targetSum) {
    // 1. use recursion
    if (root == nullptr) return false;
    if (!root->left && !root->right) {
      return targetSum == root->val;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
  bool hasPathSumDFS(TreeNode* root, int targetSum) {
    if (!root) return false;

    queue<TreeNode*> queNode;
    queue<int> queVal;
    queNode.push(root);
    queVal.push(root->val);
    while (!queNode.empty()) {
      TreeNode* node = queNode.front();
      int tmp = queVal.front();
      queNode.pop();
      queVal.pop();
      if (!node->left && !node->right) {
        if (tmp == targetSum) {
          return true;
          continue;
        }
      }
      if (node->left) {
        queNode.push(root->left);
        queVal.push(root->left->val + tmp);
      }
      if (node->right) {
        queNode.push(root->right);
        queVal.push(root->right->val + tmp);
      }
    }
    return false;
  }

  /**
   * @brief return the sum of all the nums, every path, root->val * 10 +
   * root->left->val
   *
   * @param root
   * @return int
   */
  int sumNumbers(TreeNode* root) {
    int ans = 0, num = 0;
    path(root, ans, num);
    return ans;
  }

 private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
  }

  void path(TreeNode* root, int& sum, int& num) {
    if (!root) sum = 0;
    if (!root->left && !root->right) {
      sum = num * 10 + root->val;
    }
    sum = num * 10 + root->val;
    path(root->left, sum, num);
    path(root->right, sum, num);
    num = num / 10;
  }
};

class UnionFind {
 public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          parent.push_back(i * n + j);
          ++count;
        } else {
          parent.push_back(-1);
        }
        rank.push_back(0);
      }
    }
  }

  int find(int i) {
    if (parent[i] != i) {
      parent[i] = find(parent[i]);
    }
    return parent[i];
  }

  void unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] < rank[rooty]) {
        swap(rootx, rooty);
      }
      parent[rooty] = rootx;
      if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
      --count;
    }
  }

  int getCount() const { return count; }

 private:
  vector<int> parent;
  vector<int> rank;
  int count;
};