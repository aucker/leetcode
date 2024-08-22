#include <unordered_map>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC3133: Min Array End [M][Bit ops]
   * Time: O(logx + logn), Space: O(1)
   *
   * @param n
   * @param x
   * @return long long
   */
  long long midEnd(int n, int x) {
    n--;  // n - 1
    long long ans = x;
    int i = 0, j = 0;
    while (n >> j) {
      // i-th bit of x is 0
      if ((ans >> i & 1) == 0) {
        // j-th bit of n
        ans |= (long long)(n >> j & 1) << i;
        j++;
      }
      i++;
    }
    return ans;
  }
};

/**
 * @brief LRU Cache
 *
 */
struct Node {
  int key, val;
  Node *prev, *next;
  Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), prev(nullptr), next(nullptr) {}
};

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

  void deleteNode(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void addHead(Node* node) {
    node->next = head->next;
    node->prev = head->next->prev;
    head->next->prev = node;
    head->next = node;
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
    // check if key exists
    if (get(key) != -1) {
      // exist
      Node* node = cache[key];
      node->val = value;
      deleteNode(node);
      addHead(node);
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
