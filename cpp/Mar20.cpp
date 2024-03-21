#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    ListNode* l3 = nullptr;
    ListNode** node = &l3;
    while (l1 || l2 || sum > 0) {
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      (*node) = new ListNode(sum % 10);
      sum /= 10;
      node = &((*node)->next);
    }
    return l3;
  }
};

struct Node {
  int cnt;
  int time;
  int key, val;

  Node(int _cnt, int _time, int _key, int _val)
      : cnt(_cnt), time(_time), key(_key), val(_val) {}

  bool operator<(const Node& rhs) const {
    // cnt is first compare keyword, time is second compare keyword
    return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
  }
};

class LFUCache {
 private:
  int capacity, time;
  unordered_map<int, Node> key_table;
  set<Node> S;

 public:
  LFUCache(int _capacity) {
    capacity = _capacity;
    time = 0;
    key_table.clear();
    S.clear();
  }

  int get(int key) {
    if (capacity == 0) return -1;
    auto it = key_table.find(key);
    // if no key in cache
    if (it == key_table.end()) {
      return -1;
    }

    Node cache = key_table[key];
    // reove old cache from BBT
    S.erase(cache);
    // update old cache
    cache.cnt += 1;
    cache.time = ++time;
    // add the new cache into hashtable and avl tree
    S.insert(cache);
    it->second = cache;
    return cache.val;
  }

  void put(int key, int value) {
    if (capacity == 0) return;
    auto it = key_table.find(key);
    if (it == key_table.end()) {
      // no key exist, just construct a new node
      // if capacity boom
      if (key_table.size() == capacity) {
        // find the LFU from key_table and set
        key_table.erase(S.begin()->key);
        S.erase(S.begin());
      }
      // enough space
      Node cache = Node(1, ++time, key, value);
      // add new cache into hash table and avl tree
      key_table.insert(make_pair(key, cache));
      S.insert(cache);
    } else {
      // we have this node, just update value, and move its pos
      Node cache = it->second;
      S.erase(cache);
      cache.cnt++;
      cache.time++;
      cache.val = value;
      S.insert(cache);
      it->second = cache;
    }
  }
};

struct Node1 {
  int key, val, freq;
  Node1(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};

class LFUCache1 {
 private:
  int minfreq, capacity;
  unordered_map<int, list<Node1>::iterator> key_table;
  unordered_map<int, list<Node1>> freq_table;

 public:
  LFUCache1(int _capacity) {
    minfreq = 0;
    capacity = _capacity;
    key_table.clear();
    freq_table.clear();
  }

  int get(int key) {
    if (capacity == 0) return -1;
    auto it = key_table.find(key);
    if (it == key_table.end()) return -1;
    list<Node1>::iterator node = it->second;
    int val = node->val, freq = node->freq;
    freq_table[freq].erase(node);
    // if curr linked list is null, remove from hash table, refresh minfreq
    if (freq_table[freq].size() == 0) {
      freq_table.erase(freq);
      if (minfreq == freq) minfreq++;
    }
    // insert into the freq + 1
    freq_table[freq + 1].push_front(Node1(key, val, freq + 1));
    key_table[key] = freq_table[freq + 1].begin();
    return val;
  }

  void put(int key, int value) {
    if (capacity == 0) return;
    auto it = key_table.find(key);
    if (it == key_table.end()) {
      // not node, need create one
      // check the capacity first
      if (key_table.size() == capacity) {
        // minfreq get the end node of freq_table[minFreq]
        auto it2 = freq_table[minfreq].back();
        key_table.erase(it2.key);
        freq_table[minfreq].pop_back();
        if (!freq_table[minfreq].size() == 0) {
          freq_table.erase(minfreq);
        }
      }
      freq_table[1].push_front(Node1(key, value, 1));
      key_table[key] = freq_table[1].begin();
      minfreq = 1;
    } else {
      // like get, but update cache value
      list<Node1>::iterator node = it->second;
      int freq = node->freq;
      freq_table[freq].erase(node);
      if (freq_table[freq].size() == 0) {
        freq_table.erase(freq);
        if (minfreq == freq) minfreq++;
      }
      freq_table[freq + 1].push_front(Node1(key, value, freq + 1));
      key_table[key] = freq_table[freq + 1].begin();
    }
  }
};

int main() {
  // const pointer
  int x = 5;
  int y = 20;
  int* const ptr = &x;
  *ptr = 4;
  // *ptr = &y;  // const pointer

  // const int y = 5;
  int a = 4;
  int z = 10;
  const int* ptr1 = &a;  // pointer to constant integer
  // *ptr1 = 30;
  ptr1 = &z;

  return 0;
}