#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Contest389 {
 public:
  /**
   * @brief leetcode contest 389 p1, check if lengh of 2 char equal between s
   * and reverse s
   *
   * STATUS: AC
   *
   * @param s
   * @return true
   * @return false
   */
  bool isSubstringPresent(string s) {
    // string re = s;
    // reverse(re.begin(), re.end());
    // bool ans = false;
    // // looks like this is a KMP or something
    // // leetcode
    // // edocteel
    // unordered_map<char, int> seen;
    // for (char ch : s) {
    //   seen[ch]++;
    // }
    // int maxOccur = 0;
    // for (auto& it : seen) {
    //   maxOccur = max(it.second, maxOccur);
    // }
    // if (maxOccur < 2) return false;

    int pivot = 1;
    int len = s.length();
    if (len == 1) return false;
    if (s[0] == s[1]) return true;
    while (pivot < len - 1) {
      if (s[pivot - 1] == s[pivot + 1] || s[pivot + 1] == s[pivot]) {
        return true;
      } else {
        ++pivot;
      }
    }
    return false;
  }

  /**
   * @brief p2, given a string s and char c, return total number of substrings
   * of s that start and end with c
   *
   * STATUS: AC
   *
   * @param s
   * @param c
   * @return ll
   */
  ll countSubstrings(string s, char c) {
    int n = s.length();
    // cacbcfcdedc: there 5 c, so the res is 5 + 4 + 3 + 2 + 1
    // we just count how many c in this string
    ll cnt = 0;
    for (char ch : s) {
      if (ch == c) ++cnt;
    }
    ll ans = 0;
    while (cnt >= 0) {
      ans += cnt;
      --cnt;
    }
    return ans;
  }

  /**
   * @brief p3, minimum deletions to make string k-special
   * |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string
   *
   * Perhaps I can use hashtable or hashset
   *
   * @param word
   * @param k
   * @return int
   */
  int minimumDeletions(string word, int k) {
    int ans = 0;
    unordered_map<char, int> seen;
    for (char ch : word) {
      seen[ch]++;
    }

    vector<pair<char, int>> tmp;
    for (auto& it : seen) {
      tmp.push_back(it);
    }

    // sort the vector according the second value
    sort(tmp.begin(), tmp.end(),
         [](const pair<char, int>& a, const pair<char, int>& b) {
           return a.second < b.second;
         });

    int len = tmp.size();
    // the freq is less than k, no need to remove
    if (tmp[len - 1].second - tmp[0].second <= k) {
      return 0;
    }

    int le = 0, ri = len - 1;

    while (le < ri) {
      // 1 2 3 4, k = 2
      // a b c d
      // to get the min val, we remove a rather than d
      // 1 2 3 8, k = 2
      // a b c d
      // to get the min val, we remove a, b, c
      // because their freq is less

      // 2 3 4 7, k = 2
      // a b c d
      // we remove d,
    }
    return ans;
  }

  /**
   * @brief p4: minimum moves to pick k ones
   *
   *
   * @param nums
   * @param k
   * @param maxChanges
   * @return ll
   */
  ll minimumMoves(vector<int>& nums, int k, int maxChanges) {
    ll ans = 0;

    return ans;
  }
};

class Mar17 {
 public:
  string gcdOfStrings(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();
    if (len1 % len2 != 0) return "";
    string ans;

    // abcabcabc, abc
  }

  /**
   * @brief 310: MinHeightTrees
   *
   * @param n
   * @param edges
   * @return vector<int>
   */
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    vector<int> degree(n);
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
      adj[edge[0]].emplace_back(edge[1]);
      adj[edge[1]].emplace_back(edge[0]);
      degree[edge[0]]++;
      degree[edge[1]]++;
    }
    queue<int> qu;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) {
        qu.emplace(i);
      }
    }

    int remainNodes = n;
    while (remainNodes > 2) {
      int sz = qu.size();
      remainNodes -= sz;
      for (int i = 0; i < sz; ++i) {
        int curr = qu.front();
        qu.pop();
        for (auto& v : adj[curr]) {
          if (--degree[v] == 1) {
            qu.emplace(v);
          }
        }
      }
    }
    while (!qu.empty()) {
      ans.emplace_back(qu.front());
      qu.pop();
    }
    return ans;
  }
};

/**
 * @brief Implement a Circular Queue w/ list
 *
 */
class MyCircularQueue {
 private:
  int front;
  int rear;
  int capacity;
  vector<int> elements;

 public:
  MyCircularQueue(int k) {
    this->capacity = k + 1;
    this->elements = vector<int>(capacity);
    rear = front = 0;
  }

  bool enQueue(int value) {
    if (isFull()) return false;

    elements[rear] = value;
    rear = (rear + 1) % capacity;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;

    front = (front + 1) % capacity;
    return true;
  }

  int Front() {
    if (isEmpty()) return -1;

    return elements[front];
  }

  int Rear() {
    if (isEmpty()) return -1;

    return elements[(rear - 1 + capacity) % capacity];
  }

  bool isEmpty() { return rear == front; }

  bool isFull() { return ((rear + 1) % capacity) == front; }
};

/**
 * @brief same Circular Queue
 * Implemented with LinkedList
 *
 */
class MyCircularQueue1 {
 private:
  ListNode* head;
  ListNode* tail;
  int capacity;
  int size;

 public:
  MyCircularQueue1(int k) {
    this->capacity = k;
    this->size = 0;
    this->head = this->tail = nullptr;
  }

  bool enQueue(int value) {
    if (isFull()) return false;

    ListNode* node = new ListNode(value);
    if (!head) {
      head = tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    ++size;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    ListNode* node = head;
    head = head->next;
    --size;
    delete node;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return head->val;
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return tail->val;
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }
};

class MyQueue {
 private:
  ListNode* head;
  ListNode* tail;
  int capacity;
  int size;

 public:
  MyQueue(int k) {
    this->capacity = capacity;
    this->size = 0;
    this->head = this->tail = nullptr;
  }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }

    ListNode* node = new ListNode(value);
    if (!head) {
      head = tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    ++size;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    ListNode* node = head;
    head = node->next;
    --size;
    delete node;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return head->val;
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return tail->val;
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }
};

class MyArrayQueue {
 private:
  int front;
  int rear;
  int capacity;
  vector<int> elements;

 public:
  MyArrayQueue(int k) {
    this->capacity = k + 1;
    this->elements = vector<int>(capacity);
    rear = front = 0;
  }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    elements[rear] = value;
    rear = (rear + 1) % capacity;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    front = (front + 1) % capacity;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return elements[front];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return elements[rear];
  }

  bool isEmpty() { return front == rear; }

  bool isFull() { return ((rear + 1) % capacity) == front; }
};

struct DLinkedList {
  int key, value;
  DLinkedList* prev;
  DLinkedList* next;
  DLinkedList() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DLinkedList(int _key, int _value)
      : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  unordered_map<int, DLinkedList*> cache;
  DLinkedList* head;
  DLinkedList* tail;
  int size;
  int capacity;

 public:
  LRUCache(int capacity) {
    // use dummy head and tail
    head = new DLinkedList();
    tail = new DLinkedList();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    // if cache is empty
    if (!cache.count(key)) {
      return -1;
    }

    DLinkedList* node = cache[key];
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    // we
    if (!cache.count(key)) {
      // the key not exist, create a new node
      DLinkedList* node = new DLinkedList(key, value);
      // add into hashtable
      cache[key] = node;
      // add to the head of linkedlist
      addToHead(node);
      ++size;
      if (size > capacity) {
        // if oversize, delete tail of the linkedlist
        DLinkedList* removed = removeTail();
        // delete node in hashtable
        cache.erase(removed->key);
        delete removed;
        --size;
      }
    } else {
      // if key exists, we just need to update the value, and move this node to
      // head
      DLinkedList* node = cache[key];
      node->value = value;
      moveToHead(node);
    }
  }

  void addToHead(DLinkedList* node) {
    // note that the head is dummy, which means it doesn't store value
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;

    // node become the new head
    head->next = node;
  }

  void removeNode(DLinkedList* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedList* node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkedList* removeTail() {
    DLinkedList* node = tail->prev;
    removeNode(node);
    return node;
  }
};