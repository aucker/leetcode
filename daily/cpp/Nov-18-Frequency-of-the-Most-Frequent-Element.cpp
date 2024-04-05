#include <vector>
using namespace std;

class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    // sort the vector firstly
    sort(nums.begin(), nums.end());
    long int i = 0, j = 0, sum = 0, l = 0;
    for (i; i < nums.size(); i++) {
      sum += nums[i];
      while ((i - j + 1) * nums[i] - sum > k) {
        sum -= nums[j];
        j++;
      }
      l = max(l, i - j + 1);
    }
    return l;
  }
}
