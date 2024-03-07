#include <bits/stdc++.h>
using namespace std;

// class LRUCache {
//  public:
//   LRUCache(int capacity) : cap(capacity) {}

//   int get(int key) {
//     // traverse through the list, not find
//     if (mp.find(key) == mp.end()) {
//       return -1;
//     }
//     auto kv = *mp[key];
//     cache.erase(mp[key]);
//     cache.push_front(kv);
//     mp[key] = cache.begin();
//     return kv.second;
//   }

//   void put(int key, int value) {
//     // if the key is already in the list
//     if (mp.find(key) == mp.end()) {
//       // if list is full, remove the last element
//       if (cache.size() == cap) {
//         auto last = cache.back();
//         mp.erase(last.first);
//         cache.pop_back();
//       }
//       // the key exists in the list, remove the key first
//       else {
//         cache.erase(mp[key]);
//       }
//       // relink
//       cache.push_front({key, value});
//       mp[key] = cache.begin();
//     }
//   }

//  private:
//   int cap;
//   list<pair<int, int>> cache;
//   unordered_map<int, list<pair<int, int>>::iterator> mp;
// };

class Node {
 public:
  int key, value;
  Node *prev, *next;
  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) : cap(capacity), head(nullptr), tail(nullptr) {}

  void markUsed(Node *node) {
    if (node->prev) {
      Node *before = node->prev;
      before->next = node->next;
      if (node->next) {
        node->next->prev = before;
      } else {
        tail = before;
      }
      node->next = nullptr;
      node->prev = nullptr;
      placeAtHead(node);
    }
  }

  void placeAtHead(Node *node) {
    if (head) {
      node->next = head;
      head->prev = node;
      head = node;
    } else {
      head = node;
      tail = node;
    }
  }

  void popElement() {
    if (tail) {
      Node *del = tail;
      store.erase(del->key);
      tail = tail->prev;
      if (tail) {
        tail->next = nullptr;
      } else {
        head = nullptr;
      }
      delete del;
    }
  }

  int get(int key) {
    // traverse the list, not found
    if (store.find(key) == store.end()) {
      return -1;
    }
    Node *node = store[key];
    markUsed(node);
    return store[key]->value;
  }

  void put(int key, int value) {
    if (store.find(key) != store.end()) {
      store[key]->value = value;
      markUsed(store[key]);
      return;
    }
    if (store.size() == cap) {
      popElement();
    }
    Node *node = new Node(key, value);
    placeAtHead(node);
    store[key] = node;
  }

 private:
  int cap;
  unordered_map<int, Node *> store;
  Node *head, *tail;
};

/**
 * @brief LRU Cache
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */