#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 2813: Max Elegance of K-Length subsequence
   * Time: O(nlogn), bottle neck is on Sorting
   * Space: O(N)
   *
   * @param items
   * @param k
   * @return long long
   */
  long long findMaximumElegance(vector<vector<int>>& items, int k) {
    sort(items.rbegin(), items.rend());
    long long ans = 0, total_profit = 0;
    unordered_set<int> vis;
    stack<int> duplicate;  // dup profit
    for (int i = 0; i < items.size(); i++) {
      int profit = items[i][0], category = items[i][1];
      if (i < k) {
        total_profit += profit;  // pre k profits
        if (!vis.insert(category).second) {
          duplicate.push(profit);
        }
      } else if (!duplicate.empty() && vis.insert(category).second) {
        // not exist before category
        total_profit += profit - duplicate.top();
        duplicate.pop();
      }
      ans = max(ans,
                total_profit + (long long)vis.size() * (long long)vis.size());
    }
    return ans;
  }
};