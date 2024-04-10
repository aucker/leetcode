#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC1702: max binary string after change
   *
   * Greedy, 00->10 || 10->01
   *
   * @param binary
   * @return string
   */
  string maximumBinaryString(string binary) {
    int i = binary.find('0');
    if (i < 0) {  // all 1
      return binary;
    }
    int cnt1 = count(binary.begin() + i, binary.end(), '1');
    return string(binary.size() - 1 - cnt1, '1') + '0' + string(cnt1, '1');
  }
};

/* Generally why the LFU was designed like this */
/* No need to add another size to manage for size, just use cache.size() */
struct Node {
  int key, val;
  int freq;
  Node *prev, *next;
  Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
  Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), freq(1), prev(nullptr), next(nullptr) {}
};

struct FreqList {
  int freq;
  Node *vhead, *vtail;
  FreqList(int f_) : freq(f_), vhead(new Node()), vtail(new Node()) {
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
      // this node not exist
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
      // k/v exists before
      cache[key]->val = value;
    } else {
      if (size == cache.size()) {
        // full
        popTail();
      }
      Node* node = new Node(key, value);
      cache[key] = node;
      min_freq = 1;
      addHead(node);
    }
  }
};

class LRUCache {
  unordered_map<int, Node*> cache;
  Node *head, *tail;
  int size;

 public:
  LRUCache(int capacity_)
      : size(capacity_), head(new Node()), tail(new Node()) {
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

  void moveHead(Node* node) {
    deleteNode(node);
    addHead(node);
  }

  void popTail() {
    Node* node = tail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      // k/v exist
      Node* node = cache[key];
      res = node->val;
      moveHead(node);
    }
    return res;
  }

  void put(int key, int value) {
    if (size == 0) return;
    if (get(key) != -1) {
      // k/v exist, just update value
      cache[key]->val = value;
      moveHead(cache[key]);
    } else {
      if (size == cache.size()) {
        // full, remove tail
        popTail();
      }
      Node* node = new Node(key, value);
      cache[key] = node;
      addHead(node);
    }
  }
};