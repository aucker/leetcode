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
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    int pre_sum = 0;
    unordered_map<int, ListNode*> mp;
    mp[0] = dummy;
    ListNode* curr = head;

    while (curr) {
      pre_sum += curr->val;
      if (mp.find(pre_sum) != mp.end()) {
        ListNode* to_delete = mp[pre_sum]->next;
        int tmp_sum = pre_sum + to_delete->val;
        while (to_delete != curr) {
          mp.erase(tmp_sum);
          to_delete = to_delete->next;
          tmp_sum += to_delete->val;
        }
        mp[pre_sum]->next = curr->next;
      } else {
        mp[pre_sum] = curr;
      }
      curr = curr->next;
    }
    return dummy->next;
  }

  ListNode* removeZeroSumSublists1(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    int prefix = 0;
    unordered_map<int, ListNode*> seen;
    for (ListNode* node = dummy; node; node = node->next) {
      prefix += node->val;
      seen[prefix] = node;
    }
    prefix = 0;
    for (ListNode* node = dummy; node; node = node->next) {
      prefix += node->val;
      node->next = seen[prefix]->next;
    }
    return dummy->next;
  }
};