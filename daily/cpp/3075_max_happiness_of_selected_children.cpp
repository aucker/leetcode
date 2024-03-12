#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
 public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    // ll ans = 0;
    // int sz = happiness.size();
    // sort(happiness.begin(), happiness.end());
    // ll pivot = 0;

    // while (k > 0) {
    //   if (happiness[pivot] == 0) break;
    //   ans += happiness[pivot];
    //   for (ll i = pivot; i < sz - 1; ++i) {
    //     if (happiness[i] > 0) {
    //       --happiness[i];
    //     }
    //     if (happiness[i] == 0) {
    //       --sz;
    //     }
    //   }
    //   ++pivot;
    //   --k;
    // }
    // return ans;

    ll ans = 0;
    sort(happiness.begin(), happiness.end());
    int sz = happiness.size();
    int pivot = 0;
    while (sz >= 0 && k > 0) {
      if (happiness[sz - 1] - pivot >= 0) {
        ans = ans + happiness[sz - 1] - pivot;
      } else {
        break;
      }
      ++pivot;
      --sz;
      --k;
    }
    return ans;
  }
};