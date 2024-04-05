#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief 525. Contiguous Array
   * Time Complexity: O(N)
   *
   * @param nums
   * @return int
   */
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) nums[i] = -1;
    }

    int prefix = 0, ans = 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
      prefix += nums[i];
      if (prefix == 0) {
        ans = max(ans, i + 1);
      } else if (mp.find(prefix) != mp.end()) {
        ans = max(ans, i - mp[prefix][0]);
      }
      mp[prefix].push_back(i);
    }
    return ans;
  }

  int findMaxLength1(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    int cnt = 0, ans = 0;

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        --cnt;
      } else {
        ++cnt;
      }

      if (mp.find(cnt) != mp.end()) {
        ans = max(ans, i - mp[cnt]);
      } else {
        mp[cnt] = i;
      }
    }

    for (const auto& m : mp) {
      cout << "hashtable element: " << m.second << endl;
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> tes = {1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1};
  // 12, 11, 2, 0, -1
  s.findMaxLength1(tes);
  return 0;
}