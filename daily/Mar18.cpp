#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  void path(TreeNode* node, int& sum, int& num) {
    if (!node) return;
    if (!node->left && !node->right) {
      sum = num * 10 + node->val;
    }
    num = num * 10 + node->val;
    path(node->left, sum, num);
    path(node->right, sum, num);
    num /= 10;
  }

 public:
  /**
   * @brief LC.129: Sum Root to Leaf Numbers
   * A recursive problem
   *
   * @param root
   * @return int
   */
  int sumNumbers(TreeNode* root) {
    int ans = 0, num = 0;
    path(root, ans, num);
    return ans;
  }

  /**
   * @brief LC. reverse a LinkedList
   *
   * @param head
   * @return ListNode*
   */
  ListNode* reverseList(ListNode* head) {
    ListNode* ans = nullptr;

    while (head) {
      ListNode* tmp = new ListNode(head->val);
      tmp->next = ans;
      ans = tmp;
      head = head->next;
    }

    return ans;
  }

  ListNode* reverseListIter(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  ListNode* reverseListRecur(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }

  /**
   * @brief 1156: Swap for Longest Repeated Character Substring
   * M
   *
   * @param text
   * @return int
   */
  int maxRepOpt1(string text) {
    unordered_map<char, int> count;
    for (char c : text) {
      count[c]++;
    }

    int ans = 0;
    for (int i = 0; i < text.size();) {
      int j = i;
      while (j < text.size() && text[i] == text[j]) {
        ++j;
      }
      int cur_cnt = j - i;

      // step 2:
      if (cur_cnt < count[text[i]] && (j < text.size() || i > 0)) {
        ans = max(ans, cur_cnt + 1);
      }

      // step 3
      int k = j + 1;
      while (k < text.size() && text[k] == text[i]) {
        ++k;
      }
      ans = max(ans, min(k - i, count[text[i]]));
      i = j;
    }
    return ans;
  }


  
};