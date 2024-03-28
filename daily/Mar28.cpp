#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedListS {
 private:
  int size;
  ListNode* head;

 public:
  MyLinkedListS() {
    this->size = 0;
    this->head = new ListNode(0);
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    ListNode* cur = head;
    for (int i = 0; i <= index; i++) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(size, val); }

  void addAtIndex(int index, int val) {
    if (index > size) {
      return;
    }
    index = max(0, index);
    size++;
    ListNode* pred = head;
    for (int i = 0; i < index; i++) {
      pred = pred->next;
    }
    ListNode* toAdd = new ListNode(val);
    toAdd->next = pred->next;
    pred->next = toAdd;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    size--;
    ListNode* pred = head;
    for (int i = 0; i < index; i++) {
      pred = pred->next;
    }
    ListNode* p = pred->next;
    pred->next = pred->next->next;
    delete p;
  }
};

struct DLinkedListNode {
  int val;
  DLinkedListNode *prev, *next;
  DLinkedListNode(int val_) : val(val_), prev(nullptr), next(nullptr) {}
};

class MyLinkedListD {
 private:
  int size;
  DLinkedListNode *head, *tail;

 public:
  MyLinkedListD() {
    this->size = 0;
    this->head = new DLinkedListNode(0);
    this->tail = new DLinkedListNode(0);
    head->next = tail;
    tail->prev = head;
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    DLinkedListNode* curr;
    if (index + 1 < size - index) {
      curr = head;
      for (int i = 0; i <= index; i++) {
        curr = curr->next;
      }
    } else {
      curr = tail;
      for (int i = 0; i < size - index; i++) {
        curr = curr->prev;
      }
    }
    return curr->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(size, val); }

  void addAtIndex(int index, int val) {
    if (index > size) {
      return;
    }
    index = max(0, index);
    DLinkedListNode *pred, *succ;
    if (index < size - index) {
      pred = head;
      for (int i = 0; i < index; i++) {
        pred = pred->next;
      }
      succ = pred->next;
    } else {
      succ = tail;
      for (int i = 0; i < size - index; i++) {
        succ = succ->prev;
      }
      pred = succ->prev;
    }
    size++;
    DLinkedListNode* toAdd = new DLinkedListNode(val);
    toAdd->prev = pred;
    toAdd->next = succ;
    pred->next = toAdd;
    succ->prev = toAdd;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    DLinkedListNode *pred, *succ;
    if (index < size - index) {
      pred = head;
      for (int i = 0; i < index; i++) {
        pred = pred->next;
      }
      succ = pred->next->next;
    } else {
      succ = tail;
      for (int i = 0; i < size - index - 1; i++) {
        succ = succ->prev;
      }
      pred = succ->prev->prev;
    }
    size--;
    DLinkedListNode* p = pred->next;
    pred->next = succ;
    succ->prev = pred;
    delete p;
  }
};

struct AStar {
  // manhattan distance
  static constexpr array<array<int, 6>, 6> dist = {{
      {0, 1, 2, 1, 2, 3},
      {1, 0, 1, 2, 1, 2},
      {2, 1, 0, 3, 2, 1},
      {1, 2, 3, 0, 1, 2},
      {2, 1, 2, 1, 0, 1},
      {3, 2, 1, 2, 1, 0},
  }};

  // heuristic func
  static int getH(const string& status) {
    int ret = 0;
    for (int i = 0; i < 6; i++) {
      if (status[i] != '0') {
        ret += dist[i][status[i] - '1'];
      }
    }
    return ret;
  };

  AStar(const string& status, int g)
      : status_{status}, g_{g}, h_{getH(status)} {
    f_ = g_ + g_;
  }

  bool operator<(const AStar& rhs) const { return f_ > rhs.f_; }

  string status_;
  int f_, g_, h_;
};

class Solution {
 private:
  vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                   {0, 4}, {1, 3, 5}, {2, 4}};

 public:
  /**
   * @brief LC773: Sliding puzzle
   * BFS Time: O((mn)!*mn) m: row, n: col
   * Space: O((mn)!*mn)
   *
   * @param board
   * @return int
   */
  int slidingPuzzle(vector<vector<int>>& board) {
    // enumerate status
    auto get = [&](string& status) -> vector<string> {
      vector<string> ret;
      int x = status.find('0');
      for (int y : neighbors[x]) {
        swap(status[x], status[y]);
        ret.push_back(status);
        swap(status[x], status[y]);
      }
    };

    string initial;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        initial += char(board[i][j] + '0');
      }
    }
    if (initial == "123450") {
      return 0;
    }

    queue<pair<string, int>> q;
    q.emplace(initial, 0);
    unordered_set<string> seen = {initial};

    while (!q.empty()) {
      auto [status, step] = q.front();
      q.pop();
      for (auto&& next_status : get(status)) {
        if (!seen.count(next_status)) {
          if (next_status == "123450") {
            return step + 1;
          }
          q.emplace(next_status, step + 1);
          seen.insert(move(next_status));
        }
      }
    }

    return -1;
  }

  /**
   * @brief LC773 SLiding puzzle
   * Use A* to search
   *
   * @param board
   * @return int
   */
  int slidingPuzzleAStar(vector<vector<int>>& board) {
    // enumerate status by one swap
    auto get = [&](string& status) -> vector<string> {
      vector<string> ret;
      int x = status.find('0');
      for (int y : neighbors[x]) {
        swap(status[x], status[y]);
        ret.push_back(status);
        swap(status[x], status[y]);
      }
      return ret;
    };

    string initial;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        initial += char(board[i][j] + '0');
      }
    }
    if (initial == "123450") {
      return 0;
    }

    priority_queue<AStar> q;
    q.emplace(initial, 0);
    unordered_set<string> seen = {initial};

    while (!q.empty()) {
      AStar node = q.top();
      q.pop();
      for (auto&& next_status : get(node.status_)) {
        if (!seen.count(next_status)) {
          if (next_status == "123450") {
            return node.g_ + 1;
          }
          q.emplace(next_status, node.g_ + 1);
          seen.insert(move(next_status));
        }
      }
    }
    return -1;
  }
};