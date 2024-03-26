#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Sliding window
   * traverse the array once
   * Time: O(N)
   *
   * @param nums
   * @param k
   * @return int
   */
  int numSubarrayProductLTK(vector<int>& nums, int k) {
    if (k == 0) return 0;
    int cnt = 0, pro = 1;
    for (int l = 0, r = 0; r < nums.size(); ++r) {
      pro *= nums[r];
      while (l <= r && pro >= k) {
        pro /= nums[l];
      }
      cnt += r - l + 1;
    }
    return cnt;
  }

  /**
   * @brief Max Palindrome
   *
   * @param s
   * @return string
   */
  string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;

    int maxLen = 1, begin = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    // init
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
    }

    // recursion
    for (int L = 2; L <= n; ++L) {
      for (int i = 0; i < n; ++i) {
        // right border is j
        int j = L + i - 1;
        if (j >= n) break;

        if (s[i] != s[j]) {
          dp[i][j] = false;
        } else {
          if (j - i < 3) {
            dp[i][j] = true;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        // if dp[i][L] == true, s[i..L] is palin
        if (dp[i][j] && j - i + 1 > maxLen) {
          maxLen = j - i + 1;
          begin = i;
        }
      }
    }
    return s.substr(begin, maxLen);
  }

  /**
   * @brief use corner for max palindrome
   *
   * @param s
   * @return string
   */
  string longestPalindromeOp(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto [left1, right1] = expandAroundCenter(s, i, i);
      auto [left2, right2] = expandAroundCenter(s, i, i + 1);
      if (right1 - left1 > end - start) {
        start = left1;
        end = right1;
      }
      if (right2 - left2 > end - start) {
        start = left2;
        end = right2;
      }
    }
    return s.substr(start, end - start + 1);
  }

  pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    return {left + 1, right - 1};
  }

  string longestPalindromeFast(string s) {
    int n = s.size();
    if (n < 2) return s;

    int maxLen = 1, left = 0;
    for (int i = 1; i < n; ++i) {
      if (i + 1 < n && i - 1 >= 0 && s[i - 1] == s[i + 1]) {
        int len = isPalindrome(s, i - 1, i + 1);
        if (len > maxLen) {
          maxLen = len;
          left = i - len / 2;
        }
      }

      if (s[i - 1] == s[i]) {
        int len = isPalindrome(s, i - 1, i);
        if (len > maxLen) {
          maxLen = len;
          left = i - len / 2;
        }
      }
    }

    return s.substr(left, maxLen);
  }

  int isPalindrome(string s, int left, int right) {
    while (left >= 0 && right < s.size()) {
      if (s[left] != s[right]) {
        break;
      }
      left--;
      ++right;
    }
    return right - left - 1;
  }
};