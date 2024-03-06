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
  bool hasCycle(ListNode* head) {
    // ListNode *slow = head, *fast = head->next;
    // while (slow != fast) {
    //   if (!fast or !fast->next) return false;
    //   slow = slow->next;
    //   fast = fast->next->next;
    // }
    // return true;

    ListNode *slow = head, *fast = head->next;
    while (fast and fast->next) {
      if (slow == fast) return true;
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
};