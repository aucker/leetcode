#include <unordered_map>
#include <vector>
using namespace std;

class RangeFreqQuery {
  unordered_map<int, vector<int>> pos;

 public:
  RangeFreqQuery(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      pos[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int value) {
    auto it = pos.find(value);
    if (it == pos.end()) {  // not found
      return 0;
    }

    auto& a = it->second;
    return ranges::upper_bound(a, right) - ranges::lower_bound(a, left);
  }
};

class Solution {
 public:
  /**
   * @brief LC 624: Max Distance in Arrays
   * Time: O(len), Space: O(1)
   *
   * @param arrays
   * @return int
   */
  int maxDistance(vector<vector<int>>& arrays) {
    int ans = 0;
    int mn = INT_MAX / 2, mx = INT_MIN / 2;

    for (auto& array : arrays) {
      ans = max({ans, array.back() - mn, mx - array[0]});
      mn = min(mn, array[0]);
      mx = max(mx, array.back());
    }

    return ans;
  }
};
