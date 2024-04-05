#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
 public:
  /**
   * @brief LC252: meeting rooms
   *
   * Use labmda function to sort the vector
   *
   * @param intervals 2D array
   * @return true
   * @return false
   */
  bool canAttendMettings(vector<vector<int>> &intervals) {
    auto sortByFirstNumber = [&](const vector<int> &lhs,
                                 const vector<int> &rhs) {
      return lhs[0] < rhs[0];
    };

    sort(intervals.begin(), intervals.end(),
         [&](const vector<int> &lhs, const vector<int> &rhs) {
           return lhs[0] < rhs[0];
         });

    if (intervals.size() == 1) return true;

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < intervals[i - 1][1]) {
        return false;
      }
    }
    return true;
  }

  /**
   * @brief LC253: Meeting Rooms II
   * return the min rooms needed to allocate all
   * the numbers
   *
   * We use min heap for this
   * Time: O(NlogN)
   * Space: O(N)
   *
   * @param intervals
   * @return int
   */
  int minMeetingRooms(vector<vector<int>> &intervals) {
    // if there is no intervals, return 0
    if (intervals.size() == 0) return 0;
    // min heap
    priority_queue<int, vector<int>, greater<>> allocator;
    // allocate the meeting
    sort(intervals.begin(), intervals.end());
    allocator.emplace(intervals[0][1]);

    // traverse the meeting left
    for (int i = 1; i < intervals.size(); i++) {
      // if the rooms allocated before is free, allocate this
      if (intervals[i][0] >= allocator.top()) {
        allocator.pop();
      }

      // if allocate a new room, add it to the heap
      // if allocate a old room, add to heap
      allocator.emplace(intervals[i][1]);
    }
    return allocator.size();
  }

  /**
   * @brief LC2444: Count Subarrays w/ fixed bounds
   * Hard
   *
   * @param nums
   * @param minK
   * @param maxK
   * @return ll
   */
  ll countSubarrays(vector<int> &nums, int minK, int maxK) {
    ll res = 0;
    int bad_idx = -1, left_idx = -1, right_idx = -1;

    for (int i = 0; i < nums.size(); i++) {
      if (!(minK <= nums[i] && nums[i] <= minK)) {
        bad_idx = i;
      }

      if (nums[i] == minK) {
        left_idx = i;
      }
      if (nums[i] == maxK) {
        right_idx = i;
      }
      res += max(0, min(left_idx, right_idx) - bad_idx);
    }

    return res;
  }

  /**
   * @brief LC331: verify preorder serialization of a Binary Tree
   *
   * Use STACK to simulate this process
   *
   * @param preorder
   * @return true
   * @return false
   */
  bool isValidSerialization(string preorder) {
    int n = preorder.size();
    int i = 0;
    stack<int> stk;
    stk.push(1);
    while (i < n) {
      if (stk.empty()) {
        return false;
      }

      if (preorder[i] == ',') {
        i++;
      } else if (preorder[i] == '#') {
        stk.top() -= 1;
        if (stk.top() == 0) {
          stk.pop();
        }
        i++;
      } else {
        // read a number
        while (i < n && preorder[i] != ',') {
          i++;
        }
        stk.top() -= 1;
        if (stk.top() == 0) {
          stk.pop();
        }
        stk.push(2);
      }
    }
    return stk.empty();
  }

  bool isValidSerializationCount(string preorder) {
    int n = preorder.size();
    int i = 0;
    int slot = 1;
    while (i < n) {
      if (slot == 0) return false;

      if (preorder[i] == ',') {
        i++;
      } else if (preorder[i] == '#') {
        slot--;
        i++;
      } else {
        // read a number
        while (i < n && preorder[i] != ',') {
          i++;
        }
        slot++;  // slot = slot - 1 + 2
      }
    }

    return slot == 0;
  }
};

struct Node {
  int key, val;
  int freq;
  Node *prev;
  Node *next;
  Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), freq(1), prev(nullptr), next(nullptr) {}
};

struct FreqList {
  Node *vhead;
  Node *vtail;
  int freq;
  FreqList(int f_) : freq(f_) {
    vhead = new Node();
    vtail = new Node();
    vhead->next = vtail;
    vtail->prev = vhead;
  }
};

/**
 * @brief Implement an LFU Cache
 *
 */
class LFUCache {
 private:
  unordered_map<int, Node *> cache;
  unordered_map<int, FreqList *> freq_map;
  int size;
  int min_freq;

 public:
  LFUCache(int capacity_) : size(capacity_) {}

  bool isEmpty(FreqList *list) {
    return list->vhead->next == list->vtail ? true : false;
  }

  void addHead(Node *node) {
    int freq = node->freq;
    if (freq_map.find(freq) == freq_map.end()) {
      // not find
      freq_map[freq] = new FreqList(freq);
    }
    FreqList *list = freq_map[freq];
    node->next = list->vhead->next;
    node->prev = list->vhead->next->prev;
    list->vhead->next->prev = node;
    list->vhead->next = node;
  }

  void deleteNode(Node *node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void popTail() {
    Node *node = freq_map[min_freq]->vtail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      Node *node = cache[key];
      res = node->val;
      deleteNode(node);
      node->freq++;
      if (isEmpty(freq_map[min_freq])) min_freq++;
      addHead(node);
    }

    return res;
  }

  void put(int key, int value) {
    // size is invalid
    if (size == 0) return;
    if (get(key) != -1) {
      // this key appears before
      cache[key]->val = value;
    } else {
      if (cache.size() == size) {
        popTail();
      }
      Node *node = new Node(key, value);
      cache[key] = node;
      min_freq = 1;  // new node, min is 1

      addHead(node);
    }
  }
};