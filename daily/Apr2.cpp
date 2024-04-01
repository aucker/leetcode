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
   * LC894: All possible FULL BINARY TREES
   * @brief This is a D&C solution
   *
   * @param n
   * @return vector<TreeNode*>
   */
  vector<TreeNode*> allPossibleFBTDC(int n) {
    vector<TreeNode*> fullBinaryTrees;

    if (n % 2 == 0) return fullBinaryTrees;  // this is invalid
    if (n == 1) {
      fullBinaryTrees = {new TreeNode(0)};
      return fullBinaryTrees;
    }

    for (int i = 1; i < n; i += 2) {
      // for a tree, the left and right subtree plus the root will be n
      // so, left with i, root with 1, right with n - i - 1
      vector<TreeNode*> leftSubtrees = allPossibleFBTDC(i);
      vector<TreeNode*> rightSubtrees = allPossibleFBTDC(n - 1 - i);
      for (TreeNode* leftSubtree : leftSubtrees) {
        for (TreeNode* rightSubtree : rightSubtrees) {
          TreeNode* root = new TreeNode(0, leftSubtree, rightSubtree);
          fullBinaryTrees.emplace_back(root);
        }
      }
    }
    return fullBinaryTrees;
  }

  /**
   * @brief This is DP solution
   *
   *
   * @param n
   * @return vector<TreeNode*>
   */
  vector<TreeNode*> allPossibleFBTDP(int n) {
    // if n is even, this is invalid
    if (n % 2 == 0) return {};

    vector<vector<TreeNode*>> dp(n + 1);
    dp[1] = {new TreeNode(0)};
    for (int i = 3; i <= n; i += 2) {
      for (int j = 1; j < i; j += 2) {
        for (TreeNode* leftSubtree : dp[j]) {
          for (TreeNode* rightSubtree : dp[i - i - j]) {
            TreeNode* root = new TreeNode(0, leftSubtree, rightSubtree);
            dp[i].emplace_back(root);
          }
        }
      }
    }
    return dp[n];
  }
};

struct Node {
  int key, val;
  int freq;
  Node* prev;
  Node* next;
  Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), freq(1), prev(nullptr), next(nullptr) {}
};

struct FreqList {
  int freq;
  Node* vhead;
  Node* vtail;

  FreqList(int f_) : freq(f_) {
    vhead = new Node();
    vtail = new Node();
    vhead->next = vtail;
    vtail->prev = vhead;
  }
};

class LFUCache {
 private:
  unordered_map<int, Node*> cache;
  unordered_map<int, FreqList*> freq_map;
  int min_freq;
  int size;

 public:
  LFUCache(int capacity_) : size(capacity_) {}

  bool isEmpty(FreqList* list) {
    return list->vhead->next == list->vtail ? true : false;
  }

  void deleteNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addHead(Node* node) {
    int freq = node->freq;
    if (freq_map.find(freq) == freq_map.end()) {
      // not find this freq
      freq_map[freq] = new FreqList(freq);
    }

    FreqList* list = freq_map[freq];
    node->next = list->vhead->next;
    node->prev = list->vhead->next->prev;
    list->vhead->next->prev = node;
    list->vhead->next = node;
  }

  void popTail() {
    Node* node = freq_map[min_freq]->vtail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      Node* node = cache[key];
      res = node->val;
      deleteNode(node);
      node->freq++;
      if (isEmpty(freq_map[min_freq])) min_freq++;
      addHead(node);
    }
    return res;
  }

  void put(int key, int value) {
    if (size == 0) return;
    if (get(key) != -1) {
      cache[key]->val = value;
    } else {
      if (cache.size() == size) {
        popTail();
      }
      Node* node = new Node(key, value);
      cache[key] = node;  // add to cache
      min_freq = 1;
      addHead(node);
    }
  }
};

struct DLinkedList {
  int key, val;
  DLinkedList *prev, *next;
  DLinkedList() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
  DLinkedList(int key_, int val_)
      : key(key_), val(val_), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  unordered_map<int, DLinkedList*> cache;
  DLinkedList *head, *tail;
  int size;
  int capacity;

 public:
  LRUCache(int capacity_) : capacity(capacity_), size(0) {
    head = new DLinkedList();
    tail = new DLinkedList();
    head->next = tail;
    tail->prev = head;
  }

  void addToHead(DLinkedList* node) {
    node->next = head->next;
    node->prev = head->next->prev;
    head->next->prev = node;
    head->next = node;
  }

  void deleteNode(DLinkedList* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedList* node) {
    deleteNode(node);
    addToHead(node);
  }

  DLinkedList* popTail() {
    DLinkedList* node = tail->prev;
    deleteNode(node);
    return node;
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      DLinkedList* node = cache[key];
      res = node->val;
      moveToHead(node);
    }
    return res;
  }

  void put(int key, int value) {
    if (get(key) != -1) {
      cache[key]->val = value;
      moveToHead(cache[key]);
    } else {
      if (cache.size() == capacity) {
        DLinkedList* remove = popTail();
        cache.erase(remove->key);
        --size;
        delete remove;
      }
      DLinkedList* node = new DLinkedList(key, value);
      cache[key] = node;
      addToHead(node);
      ++size;
    }
  }
};

class NQueen {
 private:
  vector<vector<string>> ans;

 public:
  vector<vector<string>> solveNQueen(int n) {
    // build the board
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);  // we sovle it from row of 0
    return ans;
  }

  void backtrack(vector<string>& board, int row) {
    // end
    if (row == board.size()) {
      ans.push_back(board);
      return;
    }

    int n = board[0].size();
    for (int col = 0; col < n; col++) {
      // remove invalid option
      if (!isValid(board, row, col)) {
        continue;
      }
      // make selection
      board[row][col] = 'Q';
      backtrack(board, row + 1);
      // undo
      board[row][col] = '.';
    }
  }

  bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // check queens are in conflict
    for (int i = 0; i < row; i++) {
      if (board[i][col] == 'Q') return false;
    }
    // check top right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[i][j] == 'Q') return false;
    }
    // top left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q') return false;
    }
    return true;
  }
};

class Sudoku {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        backtrack(board, i, j);
      }
    }
  }

  void backtrack(vector<vector<char>>& board, int i, int j) {
    int row = 9, col = 9;
    if (j == col) {
      // this is the last col, go to next row
      backtrack(board, i + 1, 0);
      return;
    }

    // if this pos has number, skip this
    if (board[i][j] != '.') {
      backtrack(board, i, j + 1);
      return;
    }

    for (char ch = '1'; ch <= '9'; ch++) {
      // if not valid, skip
      if (!isValid(board, i, j, ch)) {
        continue;
      }

      // make selection
      board[i][j] = ch;
      backtrack(board, i, j + 1);
      // undo
      board[i][j] = '.';
    }
  }

  bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
      // check repeat in row
      if (board[row][i] == ch) return false;
      // check repeat in col
      if (board[i][col] == ch) return false;

      // check subbox
      if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == ch)
        return false;
    }
    // else this is valid
    return true;
  }
};

class NQueensOP {
 public:
	/**
	 * @brief This lambda function is hard
	 * 
	 * Time: O(n^2 * n!)
	 * search tree has at most O(n!) leaves, every leaf need O(n^2) of time
	 * 
	 * Space: O(n)
	 * 
	 * @param n 
	 * @return vector<vector<string>> 
	 */
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> col(n), on_path(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
    function<void(int)> dfs = [&](int r) {
      if (r == n) {
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
          board[i] = string(col[i], '.') + 'Q' + string(n - 1 - col[i], '.');
        }
        ans.emplace_back(board);
        return;
      }

      for (int c = 0; c < n; c++) {
        int rc = r - c + n - 1;
        if (!on_path[c] && !diag1[r + c] && !diag2[rc]) {
          col[r] = c;
          // try to place the pos
          on_path[c] = diag1[r + c] = diag2[rc] = true;
          dfs(r + 1);
          // undo the ops, recover
          on_path[c] = diag1[r + c] = diag2[rc] = false;
        }
      }
    };
    dfs(0);
    return ans;
  }
};