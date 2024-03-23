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
 /**
  * @brief Reverse List
  * [1,2,3,4] -> [1,4,2,3]
  * Find the middle, reverse last half, merge two of them
  * 
  * @param head 
  */
  void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    // find the middle of list
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // reverse the last half of the list
    ListNode *prev = nullptr, *curr = slow->next;
    while (curr) {
      ListNode* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    slow->next = nullptr;

    // merge two halves
    ListNode *A = head, *B = prev;
    while (A && B) {
      ListNode* A_next = A->next;
      ListNode* B_next = B->next;
      A->next = B;
      B->next = A_next;

      A = A_next;
      B = B_next;

      /// This will cause infinite loop
      // A->next = B;
      // B->next = A->next;
      // A = A->next;
      // B = B->next;
    }
  }
};

int main() {
  Solution s;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  s.reorderList(head);
  while (head) {
    cout << "reorder list is : " << head->val << endl;
    head = head->next;
  }
  cout << "this is end " << endl;
  return 0;
}