#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief best time to sell the stock
   * this is the sliding windows solution
   *
   * @param prices
   * @return int
   */
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int le = 0, ri = 0;
    int ans = 0;
    while (ri < n) {
      while (le < ri && (prices[ri] - prices[le] < 0)) {
        ++le;
      }
      ans = max(ans, prices[ri] - prices[le]);
      ++ri;
    }
    return ans;
  }

  /**
   * @brief we use map to count the sliding window
   *
   * @param s
   * @return int
   */
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int le = 0, ri = 0;
    unordered_map<char, int> seen;
    int ans = 0;
    while (ri < n) {
      // this is not in the map
      seen[s[ri]]++;
      while (seen[s[ri]] > 1) {
        seen[s[le]]--;
        ++le;
      }

      // ans = max(ans, seen.size());
      ans = max(ans, ri - le + 1);
      ++ri;
    }
    return ans;
  }
  /**
   * @brief  this is a set solution, just like the previosu one, they are the
   * same, but there are little diffs between map and set
   *
   * @param s
   * @return int
   */
  int lengthOfLongestSubstringSet(string s) {
    int n = s.size();
    int le = 0;
    int ans = 0;
    unordered_set<char> st;
    for (int i = 0; i < n; ++i) {
      while (st.find(s[i]) != st.end()) {
        // repeat
        st.erase(s[le]);
        ++le;
      }
      ans = max(ans, i - le + 1);
      st.insert(s[i]);
    }
    return ans;
  }

  /**
   * @brief 424: Longest repeating character replacement
   * I use two pointers for this problem
   *
   * @param s
   * @param k
   * @return int
   */
  int characterReplacement(string s, int k) {
    int n = s.size();
    int le = 0, ri = 0;
    // unordered_map<char, int> seen;
    vector<int> num(26);
    int ans = 0;
    while (ri < n) {
      num[s[ri] - 'A']++;
      ans = max(ans, num[s[ri] - 'A']);
      if (ri - le + 1 - ans > k) {
        num[s[le] - 'A']--;
        ++le;
      }
      ++ri;
    }
    return ri - le;
  }

  /**
   * @brief 576: Permutation in String
   * Sliding window for this, we don't use set or map
   * we use vector for simplicity
   *
   * @param s1
   * @param s2
   * @return true
   * @return false
   */
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2) return false;
    vector<int> cnt1(26), cnt2(26);
    for (int i = 0; i < n1; ++i) {
      ++cnt1[s1[i] - 'a'];
      ++cnt2[s2[i] - 'a'];
    }
    if (cnt1 == cnt2) return true;

    for (int i = n1; i < n2; ++i) {
      ++cnt2[s2[i] - 'a'];
      --cnt2[s2[i - n1] - 'a'];
      if (cnt1 == cnt2) {
        return true;
      }
    }
    return false;
  }
  /**
   * @brief sliding window
   * this is a optimization version of sliding window
   * we don't store the whole value in the vector
   *
   * @param s1
   * @param s2
   * @return true
   * @return false
   */
  bool checkInclusionOp(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2) return false;
    vector<int> cnt(26);
    for (int i = 0; i < n1; ++i) {
      --cnt[s1[i] - 'a'];
      ++cnt[s2[i] - 'a'];
    }
    int diff = 0;
    for (int c : cnt) {
      if (c != 0) {
        ++diff;
      }
    }
    if (diff == 0) return true;

    for (int i = n1; i < n2; ++i) {
      int x = s2[i] - 'a', y = s2[i - n1] - 'a';
      if (x == y) {
        continue;
      }
      if (cnt[x] == 0) {
        ++diff;
      }
      ++cnt[x];
      if (cnt[x] == 0) {
        --diff;
      }
      if (cnt[y] == 0) {
        ++diff;
      }
      --cnt[y];
      if (cnt[y] == 0) {
        --diff;
      }
      if (diff == 0) {
        return true;
      }
    }
    return false;
  }

  /**
   * @brief  this is a two pointer version for this problem
   * this is a little bit faster than sliding window
   *
   * @param s1
   * @param s2
   * @return true
   * @return false
   */
  bool checkInclusionTwoPointer(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2) return false;
    vector<int> cnt(26);
    for (int i = 0; i < n1; ++i) {
      --cnt[s1[i] - 'a'];
    }
    int le = 0;
    for (int ri = 0; ri < n2; ++ri) {
      int x = s2[ri] - 'a';
      ++cnt[x];
      while (cnt[x] > 0) {
        --cnt[s2[le] - 'a'];
        ++le;
      }
      if (ri - le + 1 == n1) {
        return true;
      }
    }
    return false;
  }

  string minWindow(string s, string t) {
    if (s.length() < t.length()) {
      return "";
    }
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int le = 0, ri = 0;
    int valid = 0;

    int start = 0, len = INT_MAX;
    while (ri < s.length()) {
      char c = s[ri];

      // shift right windows
      ++ri;
      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) {
          valid++;
        }
      }

      // check if window need shrink
      while (le < ri && valid == need.size()) {
        if (ri - le < len) {
          start = le;
          len = ri - le;
        }
        char d = s[le];
        // shrink window
        ++le;

        if (need.count(d)) {
          if (window[d] == need[d]) {
            --valid;
          }
          window[d]--;
        }
      }
      return len == INT_MAX ? "" : s.substr(start, len);
    }
  }

  string minWindowOp(string s, string t) {
    for (const auto& c : t) {
      ++ori[c];
    }
    int le = 0, ri = -1;
    int len = INT_MAX, ansL = -1, ansR = -1;

    while (ri < int(s.size())) {
      if (ori.find(s[++ri]) != ori.end()) {
        ++cnt[s[ri]];
      }
      while (check() && le <= ri) {
        if (ri - le + 1 < len) {
          len = ri - le + 1;
          ansL = le;
        }
        if (ori.find(s[le]) != ori.end()) {
          --cnt[s[le]];
        }
        ++le;
      }
    }
    return ansL == -1 ? string() : s.substr(ansL, len);
  }

  /**
   * @brief get the max element of sliding window
   * the window shift right 1 step a time
   *
   * @param nums
   * @param k
   * @return vector<int>
   */
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.size() == 0 || k == 0) return {};
    deque<int> deque;
    vector<int> res(nums.size() - k + 1);

    for (int j = 0, i = 1 - k; j < nums.size(); ++i, ++j) {
      // remove deque nums[i-1]
      if (i > 0 && deque.front() == nums[i - 1]) {
        deque.pop_front();
      }
      while (!deque.empty() && deque.back() < nums[j]) {
        deque.pop_back();
      }
      deque.push_back(nums[j]);
      // record max of windows
      if (i >= 0) {
        res[i] = deque.front();
      }
    }
    return res;
  }

 private:
  unordered_map<char, int> ori, cnt;

  bool check() {
    for (const auto& p : ori) {
      if (cnt[p.first] < p.second) {
        return false;
      }
    }
    return true;
  }
};