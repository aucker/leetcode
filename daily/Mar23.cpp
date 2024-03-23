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
   * @brief Reverse List [LinkedList]
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

  /**
   * @brief return top k frequent element
   * Use sort in hashmap is good, like lambda function
   *
   * @param nums
   * @param k
   * @return vector<int>
   */
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> seen;
    for (int num : nums) {
      seen[num]++;
    }
    vector<pair<int, int>> sorted(seen.begin(), seen.end());
    sort(sorted.begin(), sorted.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.second > b.second;
         });

    vector<int> res;
    for (int i = 0; i < k && i < sorted.size(); ++i) {
      res.push_back(sorted[i].first);
    }
    return res;
  }

  bool isValidSokudo(vector<vector<char>>& board) {
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int subs[3][3][9] = {0};

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c != '.') {
          int idx = c - '0' - 1;
          rows[i][idx]++;
          cols[j][idx]++;
          subs[i / 3][j / 3][idx]++;
          if (rows[i][idx] > 1 || cols[i][idx] > 1 ||
              subs[i / 3][j / 3][idx] > 1) {
            return false;
          }
        }
      }
    }
    return true;
  }

  /**
   * @brief get the product of array except self
   * consider how many zeros are in this array
   *
   * @param nums
   * @return vector<int>
   */
  vector<int> productExceptSelf(vector<int>& nums) {
    int zero_cnt = 0;
    long long mult = 1;
    int flag = 0;
    int len = nums.size();
    vector<int> ans(len, 0);
    for (int i = 0; i < len; ++i) {
      if (nums[i] == 0) {
        ++zero_cnt;
        flag = i;
      }
      mult *= nums[i];
    }

    if (zero_cnt > 2) return ans;
    if (zero_cnt == 1) {
      ans[flag] = mult;
      return ans;
    }
    for (int i = 0; i < len; ++i) {
      ans[i] /= nums[i];
    }
    return ans;
  }

  /**
   * @brief Find the longest consecutive number in an array
   * we use set to track the number, we only count the current and it's forward
   *
   * @param nums
   * @return int
   */
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    for (const int& num : nums) {
      st.insert(num);
    }

    int ans = 0;
    for (const int& num : st) {
      if (!st.count(num - 1)) {
        // we can't find previous consecutive
        int curr = num;
        int currStreak = 1;

        while (st.count(curr + 1)) {
          curr++;
          currStreak++;
        }
        ans = max(ans, currStreak);
      }
    }
    return ans;
  }

  /**
   * @brief group anagrams
   * group the anagrams together
   * we use sort to handle this key(str) in the string array
   *
   * @param strs
   * @return vector<vector<string>>
   */
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      ans.emplace_back(it->second);
    }
    return ans;
  }

  vector<vector<string>> groupAnagrams1(vector<string>& strs) {
    auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t {
      return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
        return (acc << 1) ^ fn(num);
      });
    };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(
        0, arrayHash);
    for (string& str : strs) {
      array<int, 26> counts{};
      int len = str.size();
      for (int i = 0; i < len; ++i) {
        counts[str[i] - 'a']++;
      }
      mp[counts].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      ans.emplace_back(it->second);
    }
    return ans;
  }

  /**
   * @brief three sum
   * sort and blabla
   *
   * @param nums
   * @return vector<vector<int>>
   */
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // enumerate a
    for (int first = 0; first < len; ++first) {
      // if diff with last enumerate
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      // c points to the rightmost of array
      int third = len - 1;
      int target = -nums[first];
      // enumerate b
      for (int second = first + 1; second < len; ++second) {
        // need diff from last enumerate
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }
        // ensure b pointer at left of c pointer
        while (second < third && nums[second] + nums[third] > target) {
          --third;
        }
        // if pointers equal, with growth of b afterwards
        // no a + b + c = 0, and b < c of c, break
        if (second == third) {
          break;
        }
        if (nums[second] + nums[third] == target) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};

class Codec {
 public:
  // Encodes a list of strings to a single string
  string encode(vector<string>& strs) {
    string res = "";

    for (int i = 0; i < strs.size(); ++i) {
      string str = strs[i];
      res += to_string(str.size()) + "#" + str;
    }

    return res;
  }

  // Decode a single string to a list of strings
  vector<string> decode(string s) {
    vector<string> res;

    int i = 0;
    while (i < s.size()) {
      int j = i;
      while (s[j] != '#') {
        ++j;
      }
      int len = stoi(s.substr(i, j - i));
      string str = s.substr(j + 1, len);
      res.push_back(str);
      i = j + 1 + len;
    }

    return res;
  }
};

/**
 * @brief Use two stack to maintain the minstack
 *
 */
class MinStack {
  stack<int> stk;
  stack<int> min_stk;

 public:
  MinStack() { min_stk.push(INT_MAX); }

  void push(int val) {
    stk.push(val);
    min_stk.push(min(val, min_stk.top()));
  }

  void pop() {
    stk.pop();
    min_stk.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return min_stk.top(); }
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