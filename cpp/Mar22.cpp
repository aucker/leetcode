#include <bits/stdc++.h>
using namespace std;

struct DLinkedList {
  int key, val;
  DLinkedList* prev;
  DLinkedList* next;
  DLinkedList() : key(0), val(0), prev(nullptr), next(nullptr) {}
  DLinkedList(int _key, int _val)
      : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  unordered_map<int, DLinkedList*> cache;
  DLinkedList* head;
  DLinkedList* tail;
  int size, capacity;

 public:
  LRUCache(int _capacity) : size(0), capacity(_capacity) {
    head = new DLinkedList();
    tail = new DLinkedList();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (cache.find(key) == cache.end()) {
      return -1;
    }
    DLinkedList* node = cache[key];
    moveToHead(node);
    return node->val;
  }

  void put(int key, int value) {
    if (cache.find(key) == cache.end()) {
      DLinkedList* node = new DLinkedList(key, value);
      cache[key] = node;
      addToHead(node);
      ++size;
      if (size > capacity) {
        DLinkedList* remove = removeTail();
        cache.erase(remove->key);
        delete remove;
        --size;
      }
    } else {
      DLinkedList* node = cache[key];
      node->val = value;
      moveToHead(node);
    }
  }

  void addToHead(DLinkedList* node) {
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
  }

  void removeNode(DLinkedList* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedList* node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkedList* removeTail() {
    DLinkedList* node = tail->prev;
    removeNode(node);
    return node;
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution {
 public:
  /**
   * @brief Reverse the LinkedList
   *
   * @param head
   * @return ListNode*
   */
  ListNode* reverseList(ListNode* head) {
    ListNode *curr = head, *prev = head;
    while (curr) {
      ListNode* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return curr;
  }

  /**
   * @brief Two sum
   * Use two pointer or use hashtable
   *
   * @param nums
   * @param target
   * @return vector<int>
   */
  vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
      for (int j = i + 1; j < len; ++j) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }

  vector<int> twoSumMap(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(target - nums[i]) != map.end()) {
        return {i, map[target - nums[i]]};
      }
      map[nums[i]] = i;
    }
    return {};
  }

  bool isPalindrome(ListNode* head) {
    ListNode* prev = rever(head);
    ListNode* copy = copyy(head);
    while (prev && copy) {
      if (prev->val != copy->val) {
        return false;
      }
      prev = prev->next;
      copy = copy->next;
    }
    return false;
  }

  /**
   * @brief Recursion is so slow
   * 
   * @param node 
   * @return ListNode* 
   */
  ListNode* copyy(ListNode* node) {
    if (!node) return nullptr;
    ListNode* newnode = new ListNode(node->val);
    newnode->next = copyy(node->next);
    return newnode;
  }

  ListNode* rever(ListNode* node) {
    ListNode* curr = node, *prev = nullptr;
    while (curr) {
      ListNode* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return prev;
  }
};
