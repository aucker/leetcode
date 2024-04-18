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

  /* Only can climb 1 or 2 step once */
  int climbStairs(int n) {
    if (n == 1) return 1;
    int first = 1, second = 2;
    vector<int> ans(n, 0);
    ans[0] = 1;
    ans[1] = 2;
    for (int i = 2; i < n; ++i) {
      ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n - 1];
  }

  int climbStairs1(int n) {
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    return (int)round(fibn / sqrt5);
  }

  int rob(vector<int>& nums) {
    int sz = nums.size();
    if (sz == 1) return nums[0];
    if (sz == 2) return max(nums[0], nums[1]);
    vector<int> dp(sz, 0);
    for (int i = 2; i < sz; ++i) {
      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[sz - 1];
  }

  // round can't rob head and tail same time
  int robII(vector<int>& nums) {
    int sz = nums.size();
    if (sz == 1) {
      return nums[0];
    }
    if (sz == 2) return max(nums[0], nums[1]);
    return max(rob_help(nums, 0, sz - 2), rob_help(nums, 1, sz - 1));
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int sz = s.size();
    vector<bool> dp(sz + 1, false);
    dp[0] = true;
    for (int i = 1; i <= sz; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[sz];
  }

 private:
  int rob_help(vector<int>& nums, int start, int end) {
    int first = nums[start], second = max(nums[start], nums[start] + 1);
    if (start == end) return first;
    for (int i = start + 2; i <= end; ++i) {
      int tmp = second;
      second = max(second, first + nums[i]);
      first = tmp;
    }
    return second;
  }
};