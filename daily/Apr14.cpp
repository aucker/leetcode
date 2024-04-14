#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
};

/**
 * @brief We use the vector and list to
 * Implement the hashset here
 */
class MyHashSet {
  vector<list<int>> data;
  static const int base = 769;
  static int hash(int key) { return key % base; }

 public:
  MyHashSet() : data(base) {}

  void add(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it) == key) {
        return;
      }
    }
    data[h].push_back(key);
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it) == key) {
        data[h].erase(it);
        return;
      }
    }
  }

  bool contains(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it) == key) return true;
    }
    return false;
  }
};

struct Node {
  int key, val;
  int freq;
  Node *prev, *next;
  Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), prev(nullptr), next(nullptr) {}
  Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), freq(1), prev(nullptr), next(nullptr) {}
};

struct FreqList {
  int freq;
  Node *vhead, *vtail;
  FreqList(int freq_) : freq(freq_), vhead(new Node()), vtail(new Node()) {
    vhead->next = vtail;
    vtail->prev = vhead;
  }
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
    node->prev = head->prev;
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
    if (cache.find(key) != cache.end()) {
      // find
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
      // exist
      cache[key]->val = value;
    } else {
      if (size == cache.size()) {
        popTail();
      }
      Node* node = new Node(key, value);
      addHead(node);
      min_freq = 1;
      cache[key] = node;
    }
  }
};