#include <unordered_map>
#include <vector>
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
  Node(int k_, int v_)
      : key(k_), val(v_), freq(1), prev(nullptr), next(nullptr) {}
};

/**
 * @brief FreqList struct is prioritized for LFU, to track the freq of node
 *
 */
struct FreqList {
  int freq;
  Node* vhead;
  Node* vtail;

  FreqList(int f_) : freq(f_), vhead(new Node()), vtail(new Node()) {
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
  unordered_map<int, Node*> cache;
  unordered_map<int, FreqList*> freq_map;
  int size;
  int min_freq;

 public:
  LFUCache(int capacity) : size(capacity) {}

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
      Node* node = cache[key];
      node->val = value;
      node->freq++;
      deleteNode(node);
      addHead(node);
    } else {
      if (cache.size() == size) {
        popTail();
      }
      Node* node = new Node(key, value);
      cache[key] = node;  // add to cache
      min_freq = 1;       // new add, min is 1
      addHead(node);
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

 public:
  LRUCache(int capacity_) : size(capacity_) {
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
      deleteNode(node);
      addHead(node);
    }
    return res;
  }

  void put(int key, int value) {
    if (size == 0) return;
    // check if the key exist
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
};
