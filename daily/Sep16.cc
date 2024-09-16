#include <set>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: return min distance from start to destination [E]
   * there is only 2 ways to go from start to destination
   * Time: O(N), Space: O(1)
   *
   * @param distance
   * @param start
   * @param destination
   * @return int
   */
  int distanceBetweenBusStop(vector<int>& distance, int start,
                             int destination) {
    int sum = 0;
    for (int ele : distance) {
      sum += ele;
    }
    int ans = 0;
    if (start < destination) {
      for (int i = start; i < destination; i++) {
        ans += distance[i];
      }
    } else if (start > destination) {
      for (int i = destination; i < start; i++) {
        ans += distance[i];
      }
    } else {
      return 0;
    }
    return ans < (sum - ans) ? ans : (sum - ans);
  }

  /**
   * @brief Sum swap [M]
   * Pure math, use hashset to store the temp arr
   * Time: O(N), Space: O(N), find for set is O(logN)
   *
   * @param array1
   * @param array2
   * @return vector<int>
   */
  vector<int> findSwapValue(vector<int>& array1, vector<int>& array2) {
    int sum1 = 0, sum2 = 0;
    set<int> hashset;
    for (int arr : array1) {
      sum1 += arr;
    }
    for (int arr : array2) {
      sum2 += arr;
      hashset.insert(arr);
    }

    int diff = sum1 - sum2;
    if (diff % 2 != 0) {
      return {};
    }
    diff /= 2;

    vector<int> ans(2, 0);
    for (int ele : array1) {
      if (hashset.find(ele - diff) != hashset.end()) {
        ans[0] = ele;
        ans[1] = ele - diff;
        return ans;
      }
    }
    return {};
  }

  /**
   * @brief LC1180: Sliding window [E]
   * Mind the edge of window, Time: O(N) Space: O(1)
   *
   * @param s
   * @return int
   */
  int countLetters(string s) {
    int len = s.length();
    int le = 0, ri = le;
    int ans = 0;

    while (le < len && le <= ri) {
      if (s[ri] == s[le]) {
        ans++;
        ri++;
      } else {
        le++;
        ri = le;
      }
    }
    return ans;
  }
};
