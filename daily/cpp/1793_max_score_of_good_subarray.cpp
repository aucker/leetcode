#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int len = nums.size();
    int le = k - 1, ri = k + 1;
    int ans = 0;
    for (int i = nums[k];; i--) {
      while (le >= 0 && nums[le] > i) {
        --le;
      }
      while (ri < len && nums[ri] > i) {
        ++ri;
      }
      ans = max(ans, (ri - le - 1) * i);
      if (le == 0 && ri == len) {
        break;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 4, 3, 7, 4, 5};
  int k = 3;
  cout << "the res is : " << s.maximumScore(nums, k) << endl;
  return 0;
}