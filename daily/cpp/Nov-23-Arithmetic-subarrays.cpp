#include <vector>

using namespace std;
class Solution {
public:
  bool helper(vector<int>& tmp) {
    sort(tmp.begin(), tmp.end());
    if (tmp.size() <= 2) return true;
    int lent = tmp.size();
    int pivot = 0;
    for (int i = 1; i < lent - 1; i++) {
      if (tmp[i] - tmp[i-1] == tmp[i+1] - tmp[i]) {
        pivot++;
      }
    }
    if (pivot == lent - 2) return true;
    return false;
  }

  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int len = nums.size();
    vector<bool> res(len, false); // init res vector

    for (int i = 0; i < len; i++) {
      vector<int> tmp_slice(nums.begin() + l[i], nums.begin() + r[i] + 1);
      res[i] = helper(tmp_slice);
    }
    return res;
  }
};
