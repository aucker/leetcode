#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief multiple traverses
   *
   * @param garbage
   * @param travel
   * @return int
   */
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int ans = accumulate(travel.begin(), travel.end(), 0) * 3;
    for (auto& g : garbage) {
      ans += g.length();
    }

    for (char c : {'M', 'P', 'G'}) {
      for (int i = garbage.size() - 1; i && garbage[i].find(c) == string::npos;
           i--) {
        ans -= travel[i - 1];
      }
    }

    return ans;
  }

  /**
   * @brief Just traverse once
   *
   * @param garbage
   * @param travel
   * @return int
   */
  int garbageCollectionOP(vector<string>& garbage, vector<int>& travel) {
    int ans = garbage[0].length();
    int sum_t = 0;
    int t_map[4]{};
    for (int i = 1; i < garbage.size(); i++) {
      auto& s = garbage[i];
      ans += s.length();
      sum_t += travel[i - 1];
      for (char c : s) {
        ans += sum_t - t_map[c & 3];
        t_map[c & 3] = sum_t;
      }
    }
    return ans;
  }

  int garbageCollectionOP2(vector<string>& garbage, vector<int>& travel) {
    int ans = garbage[0].length();
    unordered_set<char> seen;
    for (int i = garbage.size() - 1; i; i--) {
      auto& g = garbage[i];
      seen.insert(g.begin(), g.end());
      ans += g.length() + travel[i - 1] * seen.size();
    }

    return ans;
  }
};