#include <vector>

class Solution {
public:
  vector<int> sortedSquares(vector<int> nums) {
    int len = nums.size();
    for (int i = 0; i < len ; i++) {
      nums[i] = nums[i] * nums[i];
    }

    vector<int> ans(len, 0);
    int le = 0, ri = len - 1;
    int pivot = len - 1;
    while (le <= ri) {
      if (nums[le] > nums[ri]) {
        ans[pivot] = nums[le]; // get larger
        le++;
      } else {
        ans[pivot] = nums[ri];
        ri--;
      }
      pivot--;
    }
    return ans;
  }
}
