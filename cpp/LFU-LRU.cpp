#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This Node struct is both for LFU and LRU
 * But attention, LRU doesn't need the freq, so rewrite the constructor
 * for LRU instead or there will be error here.
 * 
 */
struct Node {
  int key, val;
  int freq;
  Node* prev;
  Node* next;
  Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
  Node(int _k, int _v)
      : key(_k), val(_v), freq(1), prev(nullptr), next(nullptr) {}
};

/**
 * @brief FreqList struct is prioritized for LFU, to track the freq of node
 * 
 */
struct FreqList {
  int freq;
  Node* vhead;
  Node* vtail;

  FreqList(int _f) : freq(_f), vhead(new Node()), vtail(new Node()) {
    vhead->next = vtail;
    vtail->prev = vhead;
  }
};

/**
 * @brief LFU implementation
 * 
 */
class LFUCache {
 private:
  unordered_map<int, Node*> occ;
  unordered_map<int, FreqList*> freq_map;
  int size;
  int min_freq;

 public:
  LFUCache(int capacity) : size(capacity) {}

  bool empty(FreqList* l) { return l->vhead->next == l->vtail ? true : false; }

  void deleteNode(Node* t) {
    t->prev->next = t->next;
    t->next->prev = t->prev;
  }

  void addHead(Node* t) {
    int freq = t->freq;
    if (freq_map.find(freq) == freq_map.end()) {
      // not find
      freq_map[freq] = new FreqList(freq);
    }
    FreqList* l = freq_map[freq];
    t->next = l->vhead->next;
    l->vhead->next->prev = t;
    t->prev = l->vhead;
    l->vhead->next = t;
  }

  void popTail() {
    Node* t = freq_map[min_freq]->vtail->prev;
    deleteNode(t);
    occ.erase(t->key);
  }

  int get(int key) {
    int res = -1;
    if (occ.find(key) != occ.end()) {
      Node* t = occ[key];
      res = t->val;
      deleteNode(t);
      t->freq++;
      if (empty(freq_map[min_freq])) min_freq++;
      addHead(t);
    }
    return res;
  }

  void put(int key, int value) {
    if (size == 0) return;
    if (get(key) != -1) {
      occ[key]->val = value;
    } else {
      if (occ.size() == size) {
        popTail();
      }
      Node* t = new Node(key, value);
      occ[key] = t;
      min_freq = 1;  // the new insert is least, 1
      addHead(t);
    }
  }
};

/**
 * @brief LRU Implementation
 * 
 */
class LRUCache {
private:
  unordered_map<int, Node*> cache;
  Node* head;
  Node* tail;
  int size;
  int capacity;
public:
  LRUCache (int _capacity) : capacity(_capacity), size(0) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      Node* node = cache[key];
      res = node->val;
      moveToHead(node);
    }
    return res;
  }

  void put(int key, int value) {
    // check if the key exist
    if (cache.find(key) == cache.end()) {
      Node* node = new Node(key, value);
      cache[key] = node;
      addToHead(node);
      ++size;
      if (size > capacity) {
        Node* remove = removeTail();
        cache.erase(remove->key);
        --size;
        delete remove;
      }
    } else {
      Node* node = cache[key];
      node->val = value;
      moveToHead(node);
    }
  }

  void addToHead(Node* node) {
    node->next = head->next;
    node->prev = head->next->prev;

    head->next->prev = node;
    head->next = node;
  }

  void removeNode(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void moveToHead(Node* node) {

    removeNode(node);
    addToHead(node);
  }

  Node* removeTail() {
    Node* node = tail->prev;
    removeNode(node);
    return node;
  }
};
