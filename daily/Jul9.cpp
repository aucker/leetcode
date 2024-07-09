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
  ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur) {
      ListNode* nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }

 public:
  /**
   * @brief LC: 143: reorder list [M]
   * Time: O(n), Space: O(1)
   * Interview: bilibili
   * Just use the middle node and reverse the list
   * according the middle node, reverse the rest
   *
   * @param head
   */
  void reorderList(ListNode* head) {
    ListNode* mid = middleNode(head);
    ListNode* head2 = reverseList(mid);
    while (head2->next) {
      ListNode* nxt = head->next;
      ListNode* nxt2 = head2->next;
      head->next = head2;
      head2->next = nxt;
      head = nxt;
      head2 = nxt2;
    }
  }

 public:
  /**
   * @brief LC: 3102: Minimize Manhattan Distances [H]
   * WTF? Manhattan Distance to Chebyshev Distance
   * Time: O(nlogn), Space: O(n), n is the length of points
   *
   * @param points
   * @return int
   */
  int minimumDistance(vector<vector<int>>& points) {
    multiset<int> xs, ys;
    for (auto& p : points) {
      xs.insert(p[0] + p[1]);
      ys.insert(p[1] - p[0]);
    }

    int ans = INT_MAX;
    for (auto& p : points) {
      int x = p[0] + p[1], y = p[1] - p[0];
      xs.erase(xs.find(x));  // remove one x
      ys.erase(ys.find(y));  // remove one y

      int dx = *xs.rbegin() - *xs.begin();
      int dy = *ys.rbegin() - *ys.begin();
      ans = min(ans, max(dx, dy));

      xs.insert(x);
      ys.insert(y);
    }
    return ans;
  }
};