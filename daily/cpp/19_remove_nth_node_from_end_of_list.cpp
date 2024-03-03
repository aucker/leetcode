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
  // use pointer to solve this problem w/ O(N) time complexity
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int sz = 1;
    ListNode* cur = head;
    while (cur->next) {
      cur = cur->next;
      ++sz;
    }
    if (n == sz) {
      return head->next;
    }

    cur = head;
    while (--sz - n > 0) {
      cur = cur->next;
    }
    ListNode* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;

    return head;
  }
};