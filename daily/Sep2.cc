#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC2024: maximize the confusion of exam [M]
   * Sliding window: Time: O(N), Space: O(1)
   *
   * @param answerKey
   * @param k
   * @return int
   */
  int maxConsecutiveAnswers(string answerKey, int k) {
    int ans = 0, le = 0, cnt[2]{};
    for (int ri = 0; ri < answerKey.length(); ri++) {
      cnt[answerKey[ri] >> 1 & 1]++;
      while (cnt[0] > k & cnt[1] > k) {
        cnt[answerKey[le++] >> 1 & 1]--;
      }
      ans = max(ans, ri - le + 1);
    }
    return ans;
  }
};
