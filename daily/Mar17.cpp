#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Contest389 {
 public:
  /**
   * @brief leetcode contest 389 p1, check if lengh of 2 char equal between s
   * and reverse s
   *
   * STATUS: AC
   *
   * @param s
   * @return true
   * @return false
   */
  bool isSubstringPresent(string s) {
    // string re = s;
    // reverse(re.begin(), re.end());
    // bool ans = false;
    // // looks like this is a KMP or something
    // // leetcode
    // // edocteel
    // unordered_map<char, int> seen;
    // for (char ch : s) {
    //   seen[ch]++;
    // }
    // int maxOccur = 0;
    // for (auto& it : seen) {
    //   maxOccur = max(it.second, maxOccur);
    // }
    // if (maxOccur < 2) return false;

    int pivot = 1;
    int len = s.length();
    if (len == 1) return false;
    if (s[0] == s[1]) return true;
    while (pivot < len - 1) {
      if (s[pivot - 1] == s[pivot + 1] || s[pivot + 1] == s[pivot]) {
        return true;
      } else {
        ++pivot;
      }
    }
    return false;
  }

  /**
   * @brief p2, given a string s and char c, return total number of substrings
   * of s that start and end with c
   *
   * STATUS: AC
   *
   * @param s
   * @param c
   * @return ll
   */
  ll countSubstrings(string s, char c) {
    int n = s.length();
    // cacbcfcdedc: there 5 c, so the res is 5 + 4 + 3 + 2 + 1
    // we just count how many c in this string
    ll cnt = 0;
    for (char ch : s) {
      if (ch == c) ++cnt;
    }
    ll ans = 0;
    while (cnt >= 0) {
      ans += cnt;
      --cnt;
    }
    return ans;
  }

  /**
   * @brief p3, minimum deletions to make string k-special
   * |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string
   *
   * Perhaps I can use hashtable or hashset
   *
   * @param word
   * @param k
   * @return int
   */
  int minimumDeletions(string word, int k) {
    int ans = 0;
    unordered_map<char, int> seen;
    for (char ch : word) {
      seen[ch]++;
    }

    vector<pair<char, int>> tmp;
    for (auto& it : seen) {
      tmp.push_back(it);
    }

    // sort the vector according the second value
    sort(tmp.begin(), tmp.end(),
         [](const pair<char, int>& a, const pair<char, int>& b) {
           return a.second < b.second;
         });

    int len = tmp.size();
    // the freq is less than k, no need to remove
    if (tmp[len - 1].second - tmp[0].second <= k) {
      return 0;
    }

    int le = 0, ri = len - 1;

    while (le < ri) {
      // 1 2 3 4, k = 2
      // a b c d
      // to get the min val, we remove a rather than d
      // 1 2 3 8, k = 2
      // a b c d
      // to get the min val, we remove a, b, c
      // because their freq is less

      // 2 3 4 7, k = 2
      // a b c d
      // we remove d,
    }
    return ans;
  }

  /**
   * @brief p4: minimum moves to pick k ones
   *
   *
   * @param nums
   * @param k
   * @param maxChanges
   * @return ll
   */
  ll minimumMoves(vector<int>& nums, int k, int maxChanges) {
    ll ans = 0;

    return ans;
  }
};

class Mar17 {
 public:
  string gcdOfStrings(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();
    if (len1 % len2 != 0) return ""; 
    string ans;

    // abcabcabc, abc
  }
};