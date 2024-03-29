#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
 public:
  /**
   * @brief LC2580: Count ways to group overlapping ranges
   * M
   *
   * @param ranges
   * @return int
   */
  int countWays(vector<vector<int>>& ranges) {
    static constexpr int mod = 1e9 + 7;

    sort(ranges.begin(), ranges.end());
    int n = ranges.size();
    ll res = 1;
    for (int i = 0; i < n;) {
      int r = ranges[i][1];
      int j = i + 1;
      while (j < n && ranges[j][0] <= r) {
        r = max(r, ranges[j][1]);
        j++;
      }
      res = res * 2 % mod;
      i = j;
    }
    return res;
  }

  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // sort(points.begin(), points.end(),
    //  [&](const vector<int>& u, const vector<int>& v) {
    //  return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
    //  });
    sort(points.begin(), points.end(),
         [&](const vector<int>& lhs, const vector<int>& rhs) {
           return lhs[0] * lhs[0] + lhs[1] * lhs[1] <
                  rhs[0] * rhs[0] + rhs[1] * rhs[1];
         });
    return {points.begin(), points.begin() + k};
  }

  /**
   * @brief LC159: Longest substring w/ at most two
   * distinct chars
   *
   * SLiding window problem
   *
   * @param s
   * @return int
   */
  int lengthOfLongestSubstringTwoDistinct(string s) {
    size_t n = s.length();
    if (n < 3) return n;

    // le and ri pointer of window
    int le = 0, ri = 0;
    map<char, int> cache;
    int max_len = 2;

    while (ri < n) {
      // lt 3 chars
      cache[s[ri]] = ri;
      ri++;

      // 3 chars window
      if (cache.size() == 3) {
        int del_idx = INT_MAX;
        for (pair<char, int> ele : cache) {
          del_idx = min(del_idx, ele.second);
        }
        // delete leftmost char
        cache.erase(s[del_idx]);
        le = del_idx + 1;
      }
      max_len = max(max_len, ri - le);
    }

    return max_len;
  }

  /**
   * @brief LC243: shortest word distance
   *
   * @param wordsDict
   * @param word1
   * @param word2
   * @return int
   */
  int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int n = wordsDict.size();
    int idx1 = -1, idx2 = -1;
    int ans = n;
    for (int i = 0; i < n; i++) {
      string word = wordsDict[i];
      if (word == word1) {
        idx1 = i;
      } else if (word == word2) {
        idx2 = i;
      }
      if (idx1 >= 0 && idx2 >= 0) {
        ans = min(ans, abs(idx1 - idx2));
      }
    }

    return ans;
  }

  /**
   * @brief LC245: Shortest word distance III
   * the word1 and word2 maybe same
   *
   * @param wordsDict
   * @param word1
   * @param word2
   * @return int
   */
  int shortestWordDistance(vector<string>& wordsDict, string word1,
                           string word2) {
    int n = wordsDict.size();
    int ans = n;
    if (word1 == word2) {
      int prev =
          -1;  // this is the core, flag to check if this is first or second
      for (int i = 0; i < n; i++) {
        string word = wordsDict[i];
        if (word == word1) {
          if (prev >= 0) {
            ans = min(ans, i - prev);
          }
          prev = i;
        }
      }
    } else {
      int idx1 = -1, idx2 = -1;
      for (int i = 0; i < n; i++) {
        string word = wordsDict[i];
        if (word == word1) {
          idx1 = i;
        } else if (word == word2) {
          idx2 = i;
        }
        if (idx1 >= 0 && idx2 >= 0) {
          ans = min(ans, abs(idx1 - idx2));
        }
      }
    }

    return ans;
  }
};

/**
 * @brief LC244: disign the ds for WordDistance
 *
 * This also use a hashmap
 *
 */
class WordDistance {
 private:
  unordered_map<string, vector<int>> idmap;

 public:
  WordDistance(vector<string>& wordsDict) {
    int len = wordsDict.size();
    for (int i = 0; i < len; i++) {
      string word = wordsDict[i];
      idmap[word].emplace_back(i);
    }
  }

  int shortest(string word1, string word2) {
    vector<int> idxes1 = idmap[word1];
    vector<int> idxes2 = idmap[word2];
    int size1 = idxes1.size(), size2 = idxes2.size();
    int pos1 = 0, pos2 = 0;
    int ans = INT_MAX;
    while (pos1 < size1 && pos2 < size2) {
      int idx1 = idxes1[pos1], idx2 = idxes2[pos2];
      ans = min(ans, abs(idx1 - idx2));
      if (idx1 < idx2) {
        pos1++;
      } else {
        pos2++;
      }
    }
    return ans;
  }
};

class Dijkstra {
  /**
   * @brief LC743: Network Delay Time
   * [M]
   * use dijkstra algorithm
   *
   * @param times
   * @param n
   * @param k
   * @return int
   */
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));  // neighbor matrix
    for (auto& t : times) {
      g[t[0] - 1][t[1] - 1] = t[2];
    }

    vector<int> dis(n, INT_MAX / 2), done(n);
    dis[k - 1] = 0;
    while (true) {
      int x = -1;
      for (int i = 0; i < n; i++) {
        if (!done[i] && (x < 0 || dis[i] < dis[x])) {
          x = i;
        }
      }

      if (x < 0) {
        return *max_element(dis.begin(), dis.end());
      }

      if (dis[x] == INT_MAX / 2) {  // some node unreachable
        return -1;
      }

      done[x] = true;  // shortest path
      for (int y = 0; y < n; y++) {
        // update x neighbor shortest path
        dis[y] = min(dis[y], dis[x] + g[x][y]);
      }
    }
  }
};

class SlidingWindow {
 public:
  /**
   * @brief Count subarrays where max element appears
   * at least K times
   *
   * Sliding windows
   * I got understand, get the max element first
   * then right should keep the windows that holds the element which nums of max
   * GE k then left should try to move right, until the left bound of the window
   *
   * @param nums
   * @param k
   * @return long long
   */
  long long countSubarrays(vector<int>& nums, int k) {
    int mx = *max_element(nums.begin(), nums.end());
    ll ans = 0;
    int cnt_mx = 0, left = 0;
    for (int x : nums) {
      cnt_mx += x == mx;
      while (cnt_mx == k) {
        cnt_mx -= nums[left] == mx;
        left++;
      }
      ans += left;
    }
    return ans;
  }

 private:
  const int MOD = 1e9 + 7;

 public:
  /**
   * @brief LC907: Sum of subarry minimums
   * Sliding window
   *
   * @param arr
   * @return int
   */
  int sumSubarrayMins(vector<int>& arr) {
    int len = arr.size();
    vector<int> left(len, -1);
    vector<int> right(len, len);
    stack<int> stk;

    for (int i = 0; i < len; i++) {
      while (!stk.empty() && arr[stk.top()] >= arr[i]) {
        stk.pop();
      }
      if (!stk.empty()) {
        left[i] = stk.top();
      }
      stk.push(i);
    }
    ll sum = 0;
    for (int i = 0; i < len; i++) {
      sum += static_cast<ll>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
      sum %= MOD;
    }
    return sum;
  }
};

/* This is not so hard: Google 101 */
class Logger {
 private:
  unordered_map<string, int> msg2stamp;

 public:
  Logger() {}

  /** Use hashtable to store the map of msg2stamp **/
  bool shouldPrintMessage(int timestamp, string message) {
    auto iter = msg2stamp.find(message);
    if (iter == msg2stamp.end() || timestamp - iter->second >= 10) {
      msg2stamp[message] = timestamp;
      return true;
    } else {
      return false;
    }
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class MockInterview1 {
 public:
  /* delete duplicate in sorted linkedlist [E] */
  ListNode* deleteDuplicate(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* curr = head;
    while (curr && curr->next) {
      if (curr->val == curr->next->val) {
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }

  /* decorate Record I use BFS */
  vector<int> decorateRecord(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> ans;
    vector<TreeNode*> cur = {root};
    while (cur.size()) {
      vector<TreeNode*> nxt;
      for (auto node : cur) {
        ans.push_back(node->val);
        if (node->left) nxt.push_back(node->left);
        if (node->right) nxt.push_back(node->right);
      }
      cur = move(nxt);
    }
    return ans;
  }

  /* get the nums of longest common subsequence DP problem */
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.size(), len2 = text2.size();
    int dp[len1 + 1][len2 + 1];

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[len1][len2];
  }
};

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int val_) {
    val = val_;
    neighbors = vector<Node*>();
  }
  Node(int val_, vector<Node*> neighbors_) {
    val = val_;
    neighbors = neighbors_;
  }
};

class MockInterview2 {
 public:
  /* backtrack */
  /* Generate the all possible parenthese */
  void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
    if (cur.size() == n * 2) {
      ans.push_back(cur);
      return;
    }
    if (open < n) {
      cur.push_back('(');
      backtrack(ans, cur, open + 1, close, n);
      cur.pop_back();
    }
    if (close < open) {
      cur.push_back(')');
      backtrack(ans, cur, open, close + 1, n);
      cur.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string current;
    backtrack(res, current, 0, 0, n);
    return res;
  }

  vector<string> generateParenthesisR(int n) {
    if (n == 1) return {"()"};
    unordered_map<string, int> a;
    vector<string> ans;
    string tmp;
    for (auto& s : generateParenthesis(n - 1)) {
      for (int i = 0; i != 2 * (n - 1); i++) {
        tmp = s.substr(0, i) + "()" + s.substr(i, 2 * (n - 1));
        if (a[tmp] == 0) {
          ++a[tmp];
          ans.emplace_back(tmp);
        }
      }
    }
    return ans;
  }

  vector<string> generateParenthesisBack(int n) {
    int m = n * 2;
    vector<string> ans;
    string path(m, 0);
    function<void(int, int)> dfs = [&](int i, int open) {
      if (i == m) {
        ans.emplace_back(path);
        return;
      }
      if (open < n) {  // left
        path[i] = '(';
        dfs(i + 1, open + 1);
      }
      if (i - open < open) {  // right
        path[i] = ')';
        dfs(i + 1, open);
      }
    };
    dfs(0, 0);
    return ans;
  }

  vector<string> generateParenthesisBack2(int n) {
    vector<string> ans;
    vector<int> path;
    // balance = left - right
    function<void(int, int)> dfs = [&](int i, int balance) {
      if (path.size() == n) {
        string s(n * 2, ')');
        for (int j : path) s[j] = '(';
        ans.emplace_back(s);
        return;
      }
      // 0-balance right
      for (int close = 0; close <= balance; ++close) {
        path.push_back(i + close);  // 1 left
        dfs(i + close + 1, balance - close + 1);
        path.pop_back();
      }
    };
    dfs(0, 0);
    return ans;
  }

  /* clone the map */
  unordered_map<Node*, Node*> visited;
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return node;

    // if node has been visited, retrieve from hash
    if (visited.find(node) != visited.end()) {
      return visited[node];
    }

    // clone node, not clone its neighbor
    Node* cloneNode = new Node(node->val);
    // hash store
    visited[node] = cloneNode;

    // traverse node's neighbor update neighbor
    for (auto& neighbor : node->neighbors) {
      cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
    }
    return cloneNode;
  }

  /* Get the index of mountain array */
  /* Easy */
  int peakIndexInMountainArray(vector<int>& arr) {
    int len = arr.size();
    int le = 0, ri = len - 1;
    while (le < ri) {
      int mid = (le + ri) / 2;
      if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
        return mid;
      } else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) {
        le = mid;
      } else {
        ri = mid;
      }
    }
    return -1;
  }
};