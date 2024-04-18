#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  /**
   * @brief LC2007: Find original array from doubled array
   *
   * @param changed
   * @return vector<int>
   */
  vector<int> findOriginalArray(vector<int>& changed) {
    ranges::sort(changed);
    vector<int> ans;
    for (int x : changed) {
      auto it = mark.find(x);
      if (it == mark.end()) {  // not find this element
        mark.insert(x * 2);
        ans.push_back(x);
      } else {           // find this element x
        mark.erase(it);  // erase the mark
      }
    }
    // only all doubled marks are cleaned, changed is a double array
    // or we return empty vector
    return mark.empty() ? ans : vector<int>();
  }

  vector<int> findOriginalArray1(vector<int>& changed) {
    ranges::sort(changed);
    vector<int> ans;
    queue<int> q;
    for (int x : changed) {
      if (!q.empty()) {
        if (q.front() < x) {  // cant match
          return {};
        }
        if (q.front() == x) {  // match
          q.pop();             // erase a mark
          continue;
        }
      }
      ans.push_back(x);
      q.push(x * 2);  // add double mark
    }
    // only when all marks are removed, changed is a double array
    return q.empty() ? ans : vector<int>();
  }

  vector<int> findOriginalArray2(vector<int>& changed) {
    unordered_map<int, int> cnt;
    for (int x : changed) {
      cnt[x]++;
    }
    // handle 0
    int cnt0 = cnt[0];
    if (cnt0 % 2) return {};

    cnt.erase(0);
    vector<int> ans(cnt0 / 2);

    for (auto [key, _] : cnt) {
      int x = key;
      // if x/2 in cnt, skip
      if (x % 2 == 0 && cnt.contains(x / 2)) {
        continue;
      }

      // match x, 2x, 4x, 8x, ...
      while (cnt.contains(x)) {
        // match cnt_x x and cnt_x 2x in every loop
        int cnt_x = cnt[x];
        // not match, at least cnt_x 2x
        if (cnt_x > cnt[x * 2]) {
          return {};
        }
        ans.insert(ans.end(), cnt_x, x);
        if (cnt_x < cnt[x * 2]) {
          // some 2x  left
          cnt[x * 2] -= cnt_x;
          x *= 2;
        } else {
          x *= 4;
        }
      }
    }
    return ans;
  }
};

struct Node {
  int key, val;
  Node *prev, *next;
  int freq;
  Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), prev(nullptr), next(nullptr) {}

  Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), freq(1), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  unordered_map<int, Node*> cache;
  int size;
  Node *head, *tail;

 public:
  LRUCache(int capacity_) : size(capacity_) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }

  void addHead(Node* node) {
    node->next = head->next;
    node->prev = head->next->prev;
    head->next->prev = node;
    head->next = node;
  }

  void deleteNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void popTail() {
    Node* node = tail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {  // node exist
      Node* node = cache[key];
      res = node->val;
      deleteNode(node);
      addHead(node);
    }
    return res;
  }

  void put(int key, int value) {
    if (size == 0) return;
    if (get(key) != -1) {
      cache[key]->val = value;
    } else {
      if (size == cache.size()) {
        popTail();
      }
      Node* node = new Node(key, value);
      cache[key] = node;
      addHead(node);
    }
  }
};

struct FreqList {
  int freq;
  Node *vhead, *vtail;
  FreqList(int freq_) : freq(freq_), vhead(new Node()), vtail(new Node()) {
    vhead->next = vtail;
    vtail->prev = vhead;
  }
};

class LFUCache {
  unordered_map<int, Node*> cache;
  unordered_map<int, FreqList*> freq_map;
  int size;
  int min_freq;

 public:
  LFUCache(int capacity_) : size(capacity_) {}

  bool isEmpty(FreqList* list) {
    return list->vhead->next == list->vtail ? true : false;
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

  void deleteNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void popTail() {
    Node* node = freq_map[min_freq]->vtail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      // node exist
      Node* node = cache[key];
      res = node->val;
      node->freq++;
      deleteNode(node);
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
      if (size == cache.size()) {
        popTail();
      }
      Node* node = new Node(key, value);
      min_freq = 1;
      addHead(node);
      cache[key] = node;
    }
  }
};