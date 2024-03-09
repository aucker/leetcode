#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); ++i) {
      freq[nums[i]]++;
    }

    int max_freq = 0;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
      max_freq = max(max_freq, it->second);
    }
    int count = 0;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
      if (it->second == max_freq) {
        count += max_freq;
      }
    }
    return count;
  }
};