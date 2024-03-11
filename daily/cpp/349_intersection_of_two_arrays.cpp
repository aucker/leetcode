#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> res;
    for (const auto& num : set1) {
      // if (set2.count(num)) {
      if (set2.find(num) != set2.end()) {
        res.push_back(num);
      }
    }

    return res;
  }

};