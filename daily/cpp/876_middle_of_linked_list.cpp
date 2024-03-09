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
  ListNode* middleNode(ListNode* head) {
    /// Approache 1: get the length and traverse to middle
    // int sz = 1;
    // ListNode* cur = head;
    // while (cur->next) {
    //   cur = cur->next;
    //   ++sz;
    // }
    // int tmp = sz / 2;
    // cur = head;
    // while (tmp > 0) {
    //   cur = cur->next;
    //   --tmp;
    // }
    // return cur;

    /// Approach 2: fast and slow pointers
    ListNode *slow = head, *fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;

    /**
     * @brief  Approach 2 is faster than Approach 1
     * cause we only traverse the list once
     *
     */
  }
};