/// Link: https://leetcode.com/problems/bag-of-tokens/
/// Author: Aucker
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int sz = tokens.size();
    int score = 0, maxScore = 0;
    int le = 0, ri = sz - 1;
    while (le <= ri) {
      if (power >= tokens[le]) {
        power -= tokens[le];
        ++le;
        ++score;
        maxScore = max(maxScore, score);
      } else if (power < tokens[le] and score > 0) {
        power += tokens[ri];
        --ri;
        --score;
      } else {
        break;
      }
    }
    return maxScore;
  }
};