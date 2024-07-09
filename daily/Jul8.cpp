#include <bits/stdc++.h>

#include <type_traits>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: weekly: Wiggle sort
   * Time: O(N)
   *
   * @param nums
   */
  void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size() - 1; i += 2) {
      swap(nums[i], nums[i + 1]);
    }
  }
};

struct Node {
  int key, val;
  int freq;
  Node *prev, *next;
  // Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
  // Node(int key_, int val_) : key(key_), val(val_), prev(nullptr),
  // next(nullptr) {}
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
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void popTail() {
    Node* node = tail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
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
      // this node exist before, so just update the value
      cache[key]->val = value;
    } else {
      // this node doesn't exist before
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
  unordered_map<int, FreqList*> freq_list;
  int size;
  int min_freq;

 public:
  LFUCache(int capacity_) : size(capacity_) {}

  bool isEmpty(FreqList* list) {
    return list->vhead->next == list->vtail ? true : false;
  }

  void addHead(Node* node) {
    int freq = node->freq;
    if (freq_list.find(freq) == freq_list.end()) {
      // not find this before
      freq_list[freq] = new FreqList(freq);
    }
    FreqList* list = freq_list[freq];
    node->next = list->vhead->next;
    node->prev = list->vhead->next->prev;
    list->vhead->next->prev = node;
    list->vhead->next = node;
  }

  void deleteNode(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void removeTail() {
    Node* node = freq_list[min_freq]->vtail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      // this node exist, get val
      Node* node = cache[key];
      res = node->val;
      deleteNode(node);
      node->freq++;
      if (isEmpty(freq_list[min_freq])) {
        min_freq++;
      }
      addHead(node);
    }
    return res;
  }

  void put(int key, int value) {
    if (size == 0) return;
    if (get(key) != -1) {
      // the node exist, just update
      cache[key]->val = value;
    } else {
      if (size == cache.size()) {
        removeTail();
      }
      Node* node = new Node(key, value);
      min_freq = 1;
      cache[key] = node;
      addHead(node);
    }
  }
};