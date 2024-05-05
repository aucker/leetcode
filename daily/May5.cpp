#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int len = code.size();
    vector<int> ans(len, 0);
    if (k == 0) {
      return ans;
    }

    for (int i = 0; i < len; i++) {
      if (k > 0) {
        int tmp = k;
        while (tmp > 0) {
          ans[i] += code[(i + tmp) % len];
          tmp--;
        }
      }

      if (k < 0) {
        int tmp = k;
        while (tmp < 0) {
          ans[i] += code[(i + tmp + len) % len];
          tmp++;
        }
      }
    }

    return ans;
  }
};

class Contest396 {
 public:
  bool isValid(string word) {
    if (word.size() < 3) return false;

    bool vowel = false;
    bool non_vowel = false;
    for (char c : word) {
      if (!((c - '0' >= 0 && c - '0' <= 9) || (c - 'a' >= 0 && c - 'a' < 26) ||
            (c - 'A' >= 0 && c - 'A' < 26))) {
        return false;
      }

      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        vowel = true;
      } else if ((c - 'a' >= 0 && c - 'a' < 26) ||
                 (c - 'A' >= 0 && c - 'A' < 26)) {
        non_vowel = true;
      }
    }
    if (vowel && non_vowel) {
      return true;
    }
    return false;
  }
};