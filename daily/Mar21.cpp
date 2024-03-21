#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    // use double pointer, fast and slow
    ListNode *fast = head, *slow = head;
    while (true) {
      if (!fast || !fast->next) return nullptr;
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) break;
      // fast 2s : slow s
      // a b
      // fast: s + nb = 2s
      //
    }
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }

  /**
   * @brief search a matrix check if a value equals to target
   * Time complexity: O(m+n)
   *
   * @param matrix
   * @param target
   * @return true
   * @return false
   */
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;
    while (x < m && y >= 0) {
      if (matrix[x][y] == target) {
        return true;
      }
      if (matrix[x][y] > target) {
        --y;
      } else {
        ++x;
      }
    }
    return false;
  }

  /**
   * @brief binary search form to find a target
   * time complexity: O(mlogn)
   *
   * @param matrix
   * @param target
   * @return true
   * @return false
   */
  bool searchMatrixBS(vector<vector<int>>& matrix, int target) {
    for (const auto& row : matrix) {
      auto it = lower_bound(row.begin(), row.end(), target);
      if (it != row.end() && *it == target) {
        return true;
      }
    }
    return false;
  }

  int majorityElement(vector<int>& nums) {
    // int n = nums.size();
    // unordered_map<int, int> seen;
    // for (int num : nums) {
    //   seen[num]++;
    // }
    // for (const auto& pair : seen) {
    //   int key = pair.first;
    //   int value = pair.second;
    //   if (value > n / 2) {
    //     return key;
    //   }
    // }
    // return -1;

    int n = nums.size();
    unordered_map<int, int> seen;
    int ans = 0;
    int cnt = 0;
    for (int num : nums) {
      seen[num]++;
      if (seen[num] > cnt) {
        ans = num;
        cnt = seen[num];
      }
    }
    return ans;
  }

  int majorityElementRandom(vector<int>& nums) {
    while (true) {
      int candidate = nums[rand() % nums.size()];
      int cnt = 0;
      for (int num : nums) {
        if (num == candidate) {
          ++cnt;
        }
      }
      if (cnt > nums.size() / 2) {
        return candidate;
      }
    }
    return -1;
  }

  // divide & conquor
  int majorityElementDC(vector<int>& nums) {
    return majority_element_rec(nums, 0, nums.size() - 1);
  }

  int count_in_range(vector<int>& nums, int target, int lo, int hi) {
    int cnt = 0;
    for (int i = 0; i <= hi; ++i) {
      ++cnt;
    }
    return cnt;
  }

  int majority_element_rec(vector<int>& nums, int lo, int hi) {
    if (lo == hi) {
      return nums[lo];
    }
    int mid = (lo + hi) / 2;
    int le_majority = majority_element_rec(nums, 0, mid);
    int ri_majority = majority_element_rec(nums, mid + 1, hi);
    if (count_in_range(nums, le_majority, lo, hi) > (hi - lo + 1) / 2)
      return le_majority;
    if (count_in_range(nums, ri_majority, lo, hi) > (hi - lo + 1) / 2) {
      return ri_majority;
    }
    return -1;
  }

  /**
   * @brief we check the stack is empty or not at last
   * if it is, every char could be push in
   * or, invalid
   *
   * @param s
   * @return true
   * @return false
   */
  bool isValidParentithese(string s) {
    stack<char> stk;
    for (char ch : s) {
      if (stk.empty() && (ch == ')' || ch == '}' || ch == ']')) return false;
      if (ch == '(' || ch == '[' || ch == '{') {
        stk.push(ch);
      } else {
        if ((stk.top() == '(' && ch == ')') ||
            (stk.top() == '[' && ch == ']') ||
            (stk.top() == '{' && ch == '}')) {
          stk.pop();
        } else {
          return false;
        }
      }
      return stk.empty();
    }
  }

  /**
   * @brief Another version of valid parenthese
   *
   * @param s
   * @return true
   * @return false
   */
  bool isValid(string s) {
    stack<char> stk;
    int n = s.size();
    if (n % 2) return false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(')
        stk.push(')');
      else if (s[i] == '{')
        stk.push('}');
      else if (s[i] == '[')
        stk.push(']');
      else if (stk.empty() || s[i] != stk.top())
        return false;
      else
        stk.pop();
    }
    return stk.empty();
  }

  /**
   * @brief Sliding window for longest substring
   *
   * @param s
   * @return int
   */
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0) return 0;
    unordered_set<char> lookup;
    int maxStr = 0, left = 0;
    for (int i = 0; i < n; ++i) {
      while (lookup.find(s[i]) != lookup.end()) {
        lookup.erase(s[left]);
        ++left;
      }
      maxStr = max(maxStr, i - left + 1);
      lookup.insert(s[i]);
    }
    return maxStr;
  }

  /**
   * @brief
   * We use hashmap to store the char and its idx
   * not the freqency they appears
   *
   * @param s
   * @return int
   */
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size();
    if (n < 3) return n;
    int left = 0, right = 0;  // control the sliding windows
    int ans = 0;
    unordered_map<char, int> lookup;

    while (right < n) {
      // when sliding window has less than 3 chars
      lookup[s[right]] = right;
      ++right;

      // when sliding window has 3 chars
      if (lookup.size() == 3) {
        int del_idx = INT_MAX;
        for (pair<char, int> element : lookup) {
          del_idx = min(del_idx, element.second);
        }
        // delete left element
        lookup.erase(s[del_idx]);
        left = del_idx + 1;
      }
      ans = max(ans, right - left);
    }
    return ans;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* curr = head, *pre = nullptr;
    while (curr) {
      ListNode* tmp = curr->next;
      curr->next = pre; 
      pre = curr;
      curr = tmp;
    }
    return pre;
  }
};

struct DLinkedList {
  int key, val;
  DLinkedList* prev;
  DLinkedList* next;
  DLinkedList() : key(0), val(0), prev(nullptr), next(nullptr) {}
  DLinkedList(int _key, int _val)
      : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  unordered_map<int, DLinkedList*> cache;
  DLinkedList* head;
  DLinkedList* tail;
  int size;
  int capacity;

 public:
  LRUCache(int _capacity) : size(0), capacity(_capacity) {
    head = new DLinkedList();
    tail = new DLinkedList();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    // key exist or not
    if (cache.find(key) == cache.end()) {
      return -1;  // not exist
    }
    DLinkedList* node = cache[key];
    moveToHead(node);
    return node->val;
  }

  void put(int key, int value) {
    // check if key exist
    if (!cache.count(key)) {
      // not exist
      DLinkedList* node = new DLinkedList(key, value);
      cache[key] = node;
      addToHead(node);
      ++size;
      if (size > capacity) {
        DLinkedList* toRemove = removeTail();
        cache.erase(toRemove->key);
        delete toRemove;
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
    node->next->prev = node->prev;
    node->prev->next = node->next;
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

// #include <bits/stdc++.h>
// using namespace std;

class Slide {
  int lenOfMax(string s) {
    int n = s.size();
    if (n == 0) return 0;
    int ans = 0, left = 0;
    unordered_set<char> lookup;
    for (int i = 0; i < n; ++i) {
      if (lookup.find(s[i]) != lookup.end()) {
        // we have this char before, move right
        lookup.erase(s[left]);
        ++left;
      }
      ans = max(ans, i - left + 1);
      lookup.insert(s[i]);
    }

    return ans;
  }

  int lenOfTwo(string s) {
    int n = s.size();
    if (n < 3) return n;
    unordered_map<char, int> lookup;
    int left = 0, right = 0;
    int ans = 0;
    while (right < n) {
      // if curr windows has less than 3 chars
      // move right side window
      lookup[s[right]] = right;
      ++right;

      // if curr windows has 3 chars
      // we go to the left most windows
      if (lookup.size() == 3) {
        int del_idx = INT_MAX;
        for (pair<char, int> ele : lookup) {
          del_idx = min(del_idx, ele.second);
        }
        lookup.erase(del_idx);
        left = del_idx + 1;
      }

      ans = max(ans, right - left);
    }
    return ans;
  }
};