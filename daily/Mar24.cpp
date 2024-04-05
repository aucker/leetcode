#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
   * @brief check if a listnode is palindrome
   * we use reverse the linked list, reverse the last half of the listnode
   * and check if every val is same with the head
   *
   * @param head
   * @return true
   * @return false
   */
  bool isPalindrome(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *prev = nullptr, *curr = slow->next;
    while (curr) {
      ListNode* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }

    while (head && prev) {
      if (head->val != prev->val) {
        return false;
      }
      head = head->next;
      prev = prev->next;
    }
    return true;
  }

  /**
   * @brief I use the set to find the duplicate, but
   * this is not really fast, the time complexity is O(logN)
   *
   * @param nums
   * @return int
   */
  int findDuplicate(vector<int>& nums) {
    set<int> st;
    for (int num : nums) {
      if (st.find(num) != st.end()) {
        return num;
      }
      st.insert(num);
    }
    return -1;
  }

  int findDuplicateOp(vector<int>& nums) {
    int le = 1, ri = nums.size() - 1;
    while (le < ri) {
      int mid = (le + ri) / 2;
      int cnt = 0;
      for (int num : nums) {
        if (num <= mid) {
          cnt++;
        }
      }

      if (cnt > mid) {
        ri = mid;
      } else {
        le = mid + 1;
      }
    }
    return le;
  }

  int findDuplicateOp1(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // find intersection of two pointers
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    // find entrance of the cycle
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }

  int coinChange(vector<int>& coins, int amount) {
    if (amount < 1) return 0;
    count.resize(amount);
    return dp(coins, amount);
  }

  int coinChangeDP(vector<int>& coins, int amount) {
    int Max = amount + 1;
    vector<int> dpv(amount + 1, Max);
    dpv[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < (int)coins.size(); ++j) {
        if (coins[j] <= i) {
          dpv[i] = min(dpv[i], dpv[i - coins[j]] + 1);
        }
      }
    }
    return dpv[amount] > amount ? -1 : dpv[amount];
  }

  /**
   * @brief Sliding windows
   * This sliding window size is fixed
   *
   * @param s
   * @param k
   * @return int
   */
  int numKLenSubstrNoRepeats(string s, int k) {
    int le = 0, ri = le + k - 1;
    int n = s.size();
    if (ri >= n) return 0;
    int ans = 0;
    unordered_map<char, int> freq;
    for (int i = le; i <= ri; ++i) {
      freq[s[i]]++;
    }
    if (freq.size() == k) {
      ans++;
    }
    while (ri < n - 1) {
      freq[s[le]]--;
      if (freq[s[le]] == 0) {
        freq.erase(s[le]);
      }
      le++;
      ri++;
      freq[s[ri]]++;
      if (freq.size() == k) {
        ans++;
      }
    }
    return ans;
  }

 private:
  vector<int> count;
  int dp(vector<int>& coins, int rem) {
    if (rem < 0) return -1;
    if (rem == 0) return 0;
    if (count[rem - 1] != 0) return count[rem - 1];
    int Min = INT_MAX;
    for (int coin : coins) {
      int res = dp(coins, rem - coin);
      if (res >= 0 && res < Min) {
        Min = res + 1;
      }
    }
    count[rem - 1] = Min == INT_MAX ? -1 : Min;
    return count[rem - 1];
  }
};

class Weekly390 {
 public:
  /**
   * @brief get the max len of substring that freq is no more than 2
   * typically a sliding window problem, use le and ri to track the window
   *
   * @param s
   * @return int
   */
  int maximumLengthSubstring(string s) {
    int le = 0, ri = 0;
    int n = s.size();
    int ans = 0;
    map<char, int> seen;

    // if more than 2, le = i
    // else ri ++
    while (ri < n) {
      seen[s[ri]]++;
      while (seen[s[ri]] > 2) {
        seen[s[le]]--;
        le++;
      }
      ans = max(ans, ri - le + 1);
      ri++;
    }

    return ans;
  }

  /**
   * @brief this is a DP problem
   * or a math problem
   *
   * @param k
   * @return int
   */
  int minOperations(int k) {
    int ans = 1e9;
    for (int i = 1; i <= k; i++) {
      int now = (i - 1) + k / i - 1;
      if (k % i > 0) {
        now++;
      }
      ans = min(ans, now);
    }
    return ans;
  }

  vector<ll> mostFrequentIDs(vector<int>& a, vector<int> b) {
    vector<ll> ans;
    multiset<ll> s;
    unordered_map<int, ll> cnt;
    for (int i = 0; i < a.size(); ++i) {
      if (cnt.find(a[i]) != cnt.end()) {
        s.erase(s.find(cnt[a[i]]));
      }

      auto& it = cnt[a[i]];
      it += b[i];
      s.insert(it);
      ans.push_back(*s.rbegin());
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 3, 4, 2, 2};
  int ans = s.findDuplicateOp(nums);
  cout << "ans is: " << ans << endl;
  return 0;
}