#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findMissingRanges(vector<int>& nums, int lower,
                                        int upper) {
    nums.push_back(upper + 1);
    vector<vector<int>> ans;
    int last = lower - 1;

    for (int num : nums) {
      if (num - last > 2) {
        ans.push_back(vector<int>{last + 1, num - 1});
      } else if (num - last == 2) {
        ans.push_back(vector<int>{last + 1, last + 1});
      }
      last = num;
    }
    return ans;
  }
};
