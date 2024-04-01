#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2810: Faulty Keyboard
   * Easy 1193
   *
   * Basic queue manipulation
   *
   * @param s
   * @return string
   */
  string finalString(string s) {
    deque<char> dq;
    bool tail = true;
    for (char c : s) {
      if (c == 'i')
        tail = !tail;  // change to direction
      else if (tail)
        dq.push_back(c);  // tail
      else
        dq.push_front(c);
    }
    return tail ? string(dq.begin(), dq.end()) : string(dq.rbegin(), dq.rend());
  }

  /**
   * @brief LC58: Length of Last word
   * Easy
   * String manipulation
   *
   * @param s
   * @return int
   */
  int lenOfLastWord(string s) {
    int len = s.length();
    int i = len - 1;
    int ans = 0;
    while (i >= 0) {
      // this is first spaces
      while (s[i] == ' ') {
        i--;
        if (i < 0 || s[i] != ' ') {
          break;
        }
      }

      while (s[i] != ' ') {
        i--;
        ans++;
        if (i < 0 || s[i] == ' ') {
          break;
        }
      }
      break;
    }
    return ans;
  }

  int lenOfLastWordII(string s) {
    int ans = 0;
    bool flat = true;
    for (int i = s.size() - 2; i >= 0; i--) {
      if (s[i] != ' ' && s[i + 1] == ' ') {
        flat = false;
        ans++;
      }
      if (s[i] != ' ' && s[i + 1] != ' ') ans++;
      if (s[i] == ' ' && s[i + 1] != ' ') break;
    }
    if (flat)
      return ans + 1;
    else
      return ans;
  }

  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) return 0;
    priority_queue<int, vector<int>, greater<>> allocator;

    sort(intervals.begin(), intervals.end());
    allocator.emplace(intervals[0][1]);

    // traverse the meeting
    for (int i = 1; i < intervals.size(); i++) {
      // if room allocated before is free, allocate it
      if (intervals[i][0] >= allocator.top()) {
        allocator.pop();
      }

      allocator.emplace(intervals[i][1]);
    }
    return allocator.size();
  }
};

class Backtrack {
  /**
   * @brief Solve the sudoku problem
   *
   */
 public:
  void solveSudoku(vector<vector<char>>& board) {
    // int row[9][9]
    // int col[9][9]
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        backtrack(board, i, j);
      }
    }
    return;
  }

  bool backtrack(vector<vector<char>>& board, int i, int j) {
    int m = 9, n = 9;

    if (j == n) {
      // traverse the last col, go the next row
      return backtrack(board, i + 1, 0);
    }

    // end recursion
    if (i == m) {
      // find the valid solution, go the base case
      return true;
    }

    // if is number continue
    if (board[i][j] != '.') {
      return backtrack(board, i, j + 1);
    }

    for (char ch = '1'; ch <= '9'; ch++) {
      // invliad number
      if (!isValid(board, i, j, ch)) {
        return true;
      }
      // selection
      board[i][j] = ch;
      // next position
      if (backtrack(board, i, j + 1)) {
        return true;
      }
      board[i][j] = '.';
    }
    return false;
  }

  bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
      // check repeation in row
      if (board[row][i] == ch) return false;
      // check col
      if (board[i][col] == ch) return false;
      // check subbox
      if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == ch)
        return false;
    }
    return true;
  }

  /**
   * @brief Backtrack for NQueen problem
   *
   */
 public:
  vector<vector<string>> ans;
  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrackQueen(board, 0);
    return ans;
  }

  void backtrackQueen(vector<string>& board, int row) {
    if (row == board.size()) {
      ans.push_back(board);
      return;
    }

    int n = board[0].size();
    for (int col = 0; col < n; ++col) {
      if (!isValidQueen(board, row, col)) {
        continue;
      }
      board[row][col] = 'Q';
      backtrackQueen(board, row + 1);
      board[row][col] = '.';
    }
  }

  bool isValidQueen(vector<string>& board, int row, int col) {
    int n = board.size();

    for (int i = 0; i < row; i++) {
      if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[i][j] == 'Q') return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q') return false;
    }
    return true;
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
  int size;
  int min_freq;

 public:
  LFUCache(int capacity_) : size(capacity_) {}

  bool isEmpty(FreqList* list) {
    return list->vhead->next == list->vtail ? true : false;
  }

  void deleteNode(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void addHead(Node* node) {
    int freq = node->freq;
    if (freq_map.find(freq) == freq_map.end()) {
      // not find
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
      min_freq = 1;       // new added
      addHead(node);
    }
  }
};