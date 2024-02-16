#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findLeastNumberOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    for (auto a : arr) mp[a]++;

    vector<int> v;
    int cnt = 0;
    for (auto a : mp) {
      v.push_back(a.second);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
      if (k > v[i]) {
        k -= v[i];
        v[i] = 0;
      } else {
        v[i] -= k;
        k = 0;
      }
      if (v[i] != 0) cnt++;
    }
    return cnt;
    /**
     * 1. Use a unordered map to keep track of the frequencies.
     * 2. Seperately stored frequencies in a vector v and sort them
     * 3. To get the array of minimum unique elements, there will be only 2 
     *    condition which we have to look after
     *  3.1 
     */
};
