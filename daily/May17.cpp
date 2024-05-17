#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC:246: Strobogrammatic number
   *
   * @param num
   * @return true / false
   */
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> rotate{
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    for (int i = 0; i <= num.size() / 2; i++) {
      if (rotate.count(num[i]) == 0U) {
        return false;
      }
      if (rotate[num[i]] != num[num.size() - i - 1]) {
        return false;
      }
    }

    return true;
  }

  /**
   * @brief LC: 826 Most Profit Assigning Work
   *
   * @param difficulty
   * @param profit
   * @param worker
   * @return int
   */
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    int n = difficulty.size();
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++) {
      jobs[i] = {difficulty[i], profit[i]};
    }

    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());
    int ans = 0, j = 0, max_profit = 0;
    for (int w : worker) {
      while (j < n && jobs[j].first <= w) {
        max_profit = max(max_profit, jobs[j++].second);
      }
      ans += max_profit;
    }

    return ans;
  }
};
